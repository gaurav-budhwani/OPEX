# Convolution & Pipeline Operators

OPEX introduces dedicated syntax operators for computer vision workflows.

---

## The 2D Convolution Operator (`**`)

The infix `**` operator performs 2D spatial convolution between an `IMAGE` (or `MATRIX`) and a `KERNEL`:

$$\text{Output}(x, y) = \sum_{i=-k}^{k} \sum_{j=-k}^{k} \text{Input}(x+i, y+j) \cdot \text{Kernel}(i, j)$$

```opex
KERNEL sobelX := [[-1, 0, 1], [-2, 0, 2], [-1, 0, 1]]
AUTO img := LOAD("sample.jpg")
AUTO gray := GRAYSCALE(img)

// Compute horizontal gradient map via convolution
AUTO edgesX := gray ** sobelX
```

### Edge Handling
The OPEX runtime automatically clamps pixel boundaries with zero-padding to prevent memory overflow at image borders.

---

## The Pipeline Operator (`|>`)

Inspired by modern functional languages, the `|>` pipeline operator feeds the output of the left-hand expression as the first argument into the right-hand function call:

```opex
// Traditional nested syntax:
AUTO result := THRESHOLD(GRAYSCALE(LOAD("input.jpg")), 50)

// Equivalent clean OPEX pipeline syntax:
AUTO result := LOAD("input.jpg") 
               |> GRAYSCALE 
               |> THRESHOLD(50)
```

### Combined Pipeline Example
```opex
AUTO edgeMap := ((gray ** sobelX) + (gray ** sobelY)) |> THRESHOLD(50)
```
