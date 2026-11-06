# Edge Detection Pipeline

This example demonstrates the complete computer vision capability of OPEX by computing horizontal and vertical image gradients using Sobel operators, combining them, and applying threshold segmentation.

---

## OPEX Source (`tests/edge_detection.opx`)

```opex
PROGRAM EdgeDetection
BEGIN
    // Define 3x3 Sobel spatial kernels
    KERNEL sobelX := [[-1, 0, 1],
                      [-2, 0, 2],
                      [-1, 0, 1]]

    KERNEL sobelY := [[-1, -2, -1],
                      [ 0,  0,  0],
                      [ 1,  2,  1]]

    // Load and convert to grayscale
    AUTO img  := LOAD("input.jpg")
    AUTO gray := GRAYSCALE(img)

    // Apply Sobel convolution operators
    AUTO edgesX := gray ** sobelX
    AUTO edgesY := gray ** sobelY

    // Combine gradient maps (element-wise addition)
    AUTO combined := edgesX + edgesY

    // Threshold via pipeline operator to produce binary edge map
    AUTO edgeMap := combined |> THRESHOLD(50)

    // Save output and print metadata
    SAVE(edgeMap, "edges.png")
    PRINT "Edge detection complete: {img.width}x{img.height}"
END
```

---

## Running the Example

```bash
./opex --run tests/edge_detection.opx
```

### Execution Log
```
[OPEX Runtime] Loaded image 'input.jpg' (synthesized 64x64 test pattern)
[OPEX Runtime] Saved image: edges.png (64x64)
Edge detection complete: 64x64
```

