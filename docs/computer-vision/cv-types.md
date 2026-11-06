---
icon: material/image-outline
---

# Computer Vision Types

A core innovation in OPEX is its native, first-class support for computer vision data structures.

---

## 1. `IMAGE`

Represents a 2D multi-channel or single-channel image. An `IMAGE` carries width, height, and channel metadata alongside its underlying pixel buffer.

### Declaration & Dimensions
```opex
// Uninitialized image variable (loaded via LOAD)
VAR img : IMAGE;

// Direct property access
PRINT "Width:    {img.width}";
PRINT "Height:   {img.height}";
PRINT "Channels: {img.channels}";
```

---

## 2. `KERNEL`

A `KERNEL` is a 2D spatial convolution matrix. Kernels typically have odd dimensions (e.g. 3x3, 5x5) so they possess a unique center origin.

### Kernel Literals
```opex
// 3x3 Sobel Horizontal Derivative Kernel
KERNEL sobelX := [[-1, 0, 1],
                  [-2, 0, 2],
                  [-1, 0, 1]]

// 3x3 Sobel Vertical Derivative Kernel
KERNEL sobelY := [[-1, -2, -1],
                  [ 0,  0,  0],
                  [ 1,  2,  1]]

// 3x3 Box Blur Kernel
KERNEL blurKernel := [[1, 1, 1],
                      [1, 1, 1],
                      [1, 1, 1]]
```

---

## 3. `MATRIX`

Represents a general 2D floating-point matrix for linear transformations, affine mappings, and coordinate projections.

```opex
VAR transform : MATRIX;
```

---

## 4. `PIXEL`

Represents a single multi-channel color or intensity value:

| Field | Type | Meaning |
| :--- | :--- | :--- |
| `.r` | `INT` | Red channel (0–255) |
| `.g` | `INT` | Green channel (0–255) |
| `.b` | `INT` | Blue channel (0–255) |
| `.v` | `INT` | Grayscale intensity value |

```opex
VAR px : PIXEL;
px.r := 255;
px.g := 128;
px.b := 0;
```

