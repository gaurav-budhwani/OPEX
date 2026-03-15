PROGRAM EdgeDetection
BEGIN
    // Define Sobel kernels
    KERNEL sobelX := [[-1, 0, 1],
                       [-2, 0, 2],
                       [-1, 0, 1]]

    KERNEL sobelY := [[-1, -2, -1],
                       [ 0,  0,  0],
                       [ 1,  2,  1]]

    // Load and convert to grayscale
    AUTO img  := LOAD("input.jpg")
    AUTO gray := GRAYSCALE(img)

    // Apply Sobel operators
    AUTO edgesX := gray ** sobelX
    AUTO edgesY := gray ** sobelY

    // Combine edge maps (element-wise addition)
    AUTO combined := edgesX + edgesY

    // Threshold to produce binary edge map
    AUTO edgeMap := THRESHOLD(combined, 50)

    SAVE(edgeMap, "edges.png")
    PRINT "Edge detection complete: {img.width}x{img.height}"
END
