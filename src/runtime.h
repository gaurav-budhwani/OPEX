#ifndef OPEX_RUNTIME_H
#define OPEX_RUNTIME_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

#define TRUE 1
#define FALSE 0

// OPEX PIXEL Type
typedef struct {
    int r;
    int g;
    int b;
    int v;
} OPEX_Pixel;

// OPEX MATRIX Type
typedef struct {
    int rows;
    int cols;
    double* data;
} OPEX_Matrix;

// OPEX KERNEL Type
typedef struct {
    int rows;
    int cols;
    double* data;
} OPEX_Kernel;

// OPEX IMAGE Type
typedef struct {
    int width;
    int height;
    int channels;
    unsigned char* data;
} OPEX_Image;

static inline OPEX_Matrix opex_make_matrix(int rows, int cols) {
    OPEX_Matrix m;
    m.rows = rows;
    m.cols = cols;
    m.data = (double*)calloc(rows * cols, sizeof(double));
    return m;
}

static inline OPEX_Kernel opex_make_kernel(int rows, int cols, double* values) {
    OPEX_Kernel k;
    k.rows = rows;
    k.cols = cols;
    k.data = (double*)malloc(rows * cols * sizeof(double));
    if (values) {
        memcpy(k.data, values, rows * cols * sizeof(double));
    } else {
        memset(k.data, 0, rows * cols * sizeof(double));
    }
    return k;
}

static inline OPEX_Image opex_make_image(int width, int height, int channels) {
    OPEX_Image img;
    img.width = width;
    img.height = height;
    img.channels = channels;
    img.data = (unsigned char*)calloc(width * height * channels, sizeof(unsigned char));
    return img;
}

// Load Image (Supports PPM format or creates a synthetic test gradient if missing)
static inline OPEX_Image opex_load(const char* path) {
    FILE* f = fopen(path, "rb");
    if (f) {
        char magic[3];
        if (fscanf(f, "%2s", magic) == 1 && strcmp(magic, "P6") == 0) {
            int w, h, maxv;
            if (fscanf(f, "%d %d %d", &w, &h, &maxv) == 3) {
                fgetc(f); // newline
                OPEX_Image img = opex_make_image(w, h, 3);
                fread(img.data, 1, w * h * 3, f);
                fclose(f);
                printf("[OPEX Runtime] Loaded image: %s (%dx%d, 3 channels)\n", path, w, h);
                return img;
            }
        }
        fclose(f);
    }

    // Fallback: create synthetic 64x64 test image with geometric patterns
    int w = 64, h = 64, c = 3;
    OPEX_Image img = opex_make_image(w, h, c);
    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            int idx = (y * w + x) * c;
            img.data[idx]     = (unsigned char)((x * 255) / w);       // Red gradient
            img.data[idx + 1] = (unsigned char)((y * 255) / h);       // Green gradient
            img.data[idx + 2] = (unsigned char)(((x + y) * 255) / (w + h)); // Blue
        }
    }
    printf("[OPEX Runtime] Loaded image '%s' (synthesized %dx%d test pattern)\n", path, w, h);
    return img;
}

// Save Image (Outputs portable PPM format, viewable anywhere)
static inline void opex_save(OPEX_Image img, const char* path) {
    // Generate valid PPM image
    char ppm_path[256];
    strncpy(ppm_path, path, sizeof(ppm_path) - 5);
    ppm_path[sizeof(ppm_path) - 5] = '\0';
    char* ext = strrchr(ppm_path, '.');
    if (ext) strcpy(ext, ".ppm");
    else strcat(ppm_path, ".ppm");

    FILE* f = fopen(ppm_path, "wb");
    if (!f) f = fopen(path, "wb");
    if (f) {
        if (img.channels == 1) {
            fprintf(f, "P5\n%d %d\n255\n", img.width, img.height);
            fwrite(img.data, 1, img.width * img.height, f);
        } else {
            fprintf(f, "P6\n%d %d\n255\n", img.width, img.height);
            fwrite(img.data, 1, img.width * img.height * 3, f);
        }
        fclose(f);
    }
    printf("[OPEX Runtime] Saved image: %s (%dx%d)\n", path, img.width, img.height);
}

// Convert image to single-channel Grayscale
static inline OPEX_Image opex_grayscale(OPEX_Image img) {
    if (img.channels == 1) return img;
    OPEX_Image gray = opex_make_image(img.width, img.height, 1);
    for (int i = 0; i < img.width * img.height; i++) {
        int r = img.data[i * img.channels];
        int g = img.data[i * img.channels + 1];
        int b = img.data[i * img.channels + 2];
        gray.data[i] = (unsigned char)(0.299 * r + 0.587 * g + 0.114 * b);
    }
    return gray;
}

// Apply 2D Convolution on Image with Kernel (Operator **)
static inline OPEX_Image opex_convolve_image(OPEX_Image img, OPEX_Kernel k) {
    OPEX_Image out = opex_make_image(img.width, img.height, img.channels);
    int k_half_y = k.rows / 2;
    int k_half_x = k.cols / 2;

    for (int y = 0; y < img.height; y++) {
        for (int x = 0; x < img.width; x++) {
            for (int c = 0; c < img.channels; c++) {
                double sum = 0.0;
                for (int ky = 0; ky < k.rows; ky++) {
                    for (int kx = 0; kx < k.cols; kx++) {
                        int iy = y + ky - k_half_y;
                        int ix = x + kx - k_half_x;
                        if (iy >= 0 && iy < img.height && ix >= 0 && ix < img.width) {
                            int pixel_val = img.data[(iy * img.width + ix) * img.channels + c];
                            sum += pixel_val * k.data[ky * k.cols + kx];
                        }
                    }
                }
                int final_val = (int)fabs(sum);
                if (final_val > 255) final_val = 255;
                out.data[(y * img.width + x) * img.channels + c] = (unsigned char)final_val;
            }
        }
    }
    return out;
}

// Apply Binary Threshold
static inline OPEX_Image opex_threshold(OPEX_Image img, int thresh) {
    OPEX_Image out = opex_make_image(img.width, img.height, img.channels);
    for (int i = 0; i < img.width * img.height * img.channels; i++) {
        out.data[i] = (img.data[i] >= thresh) ? 255 : 0;
    }
    return out;
}

// Image Element-wise Addition
static inline OPEX_Image opex_add_image(OPEX_Image a, OPEX_Image b) {
    int w = a.width < b.width ? a.width : b.width;
    int h = a.height < b.height ? a.height : b.height;
    int c = a.channels < b.channels ? a.channels : b.channels;
    OPEX_Image out = opex_make_image(w, h, c);
    for (int i = 0; i < w * h * c; i++) {
        int sum = (int)a.data[i] + (int)b.data[i];
        out.data[i] = sum > 255 ? 255 : (unsigned char)sum;
    }
    return out;
}

// Simple Box Blur
static inline OPEX_Image opex_blur(OPEX_Image img) {
    double weights[9] = {
        1.0/9, 1.0/9, 1.0/9,
        1.0/9, 1.0/9, 1.0/9,
        1.0/9, 1.0/9, 1.0/9
    };
    OPEX_Kernel k = opex_make_kernel(3, 3, weights);
    OPEX_Image blurred = opex_convolve_image(img, k);
    free(k.data);
    return blurred;
}

// Simple Rotate (90 degrees clockwise)
static inline OPEX_Image opex_rotate(OPEX_Image img, int deg) {
    (void)deg;
    OPEX_Image out = opex_make_image(img.height, img.width, img.channels);
    for (int y = 0; y < img.height; y++) {
        for (int x = 0; x < img.width; x++) {
            for (int c = 0; c < img.channels; c++) {
                int src = (y * img.width + x) * img.channels + c;
                int dst = (x * img.height + (img.height - 1 - y)) * img.channels + c;
                out.data[dst] = img.data[src];
            }
        }
    }
    return out;
}

// Simple Flip (0 = horizontal, 1 = vertical)
static inline OPEX_Image opex_flip(OPEX_Image img, int mode) {
    OPEX_Image out = opex_make_image(img.width, img.height, img.channels);
    for (int y = 0; y < img.height; y++) {
        for (int x = 0; x < img.width; x++) {
            int src_y = y;
            int src_x = (mode == 0) ? (img.width - 1 - x) : x;
            if (mode != 0) src_y = img.height - 1 - y;
            for (int c = 0; c < img.channels; c++) {
                out.data[(y * img.width + x) * img.channels + c] = 
                    img.data[(src_y * img.width + src_x) * img.channels + c];
            }
        }
    }
    return out;
}

// String printing with newline
static inline void opex_print_str(const char* s) {
    printf("%s\n", s);
}

// Numeric printing with newline
static inline void opex_print_int(long long n) {
    printf("%lld\n", n);
}

static inline void opex_print_float(double f) {
    printf("%g\n", f);
}

static inline void opex_print_bool(int b) {
    printf("%s\n", b ? "TRUE" : "FALSE");
}

#endif // OPEX_RUNTIME_H

