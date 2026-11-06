# Built-in Computer Vision Operations

OPEX includes a set of native built-in operations for image processing and transformation.

---

## File I/O

### `LOAD(path : STRING) : IMAGE`
Loads an image file into memory. If the file is not found, the OPEX runtime automatically synthesizes a geometric test gradient to allow algorithm verification without local assets.

```opex
AUTO img := LOAD("landscape.ppm")
```

### `SAVE(img : IMAGE, path : STRING) : VOID`
Writes the image buffer to disk in standard PPM/BMP format.

```opex
SAVE(img, "output.ppm")
```

---

## Color Space & Filters

### `GRAYSCALE(img : IMAGE) : IMAGE`
Converts a 3-channel RGB image into a single-channel luminance intensity map using ITU-R BT.601 coefficients:

$$Y = 0.299R + 0.587G + 0.114B$$

```opex
AUTO gray := GRAYSCALE(img)
```

### `THRESHOLD(img : IMAGE, cutoff : INT) : IMAGE`
Performs binary segmentation. Pixels with intensity $\ge \text{cutoff}$ are mapped to 255 (white); otherwise 0 (black).

```opex
AUTO binaryMask := THRESHOLD(gray, 128)
```

### `BLUR(img : IMAGE) : IMAGE`
Applies a normalized $3 \times 3$ box-filter spatial smoothing kernel.

```opex
AUTO smoothed := BLUR(img)
```

---

## Geometric Transformations

### `ROTATE(img : IMAGE, degrees : INT) : IMAGE`
Rotates the image clockwise by 90-degree increments, swapping row and column dimensions.

```opex
AUTO rotated := ROTATE(img, 90)
```

### `FLIP(img : IMAGE, mode : INT) : IMAGE`
Flips the image along an axis (`mode = 0` for horizontal reflection, `mode = 1` for vertical).

```opex
AUTO mirrored := FLIP(img, 0)
```
