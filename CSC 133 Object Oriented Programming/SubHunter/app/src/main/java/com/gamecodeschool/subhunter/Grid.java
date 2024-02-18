// Grid.java
// Draws the starting grid.

package com.gamecodeschool.subhunter;
import android.graphics.Canvas;
import android.graphics.Color;
import android.graphics.Paint;

public class Grid implements Drawable {
    private int gridWidth = 40; // Width of starting grid
    private int gridHeight; // Height of starting grid
    private int blockSize; // Size of blocks to place on grid

    // Constructor
    public Grid(int gridWidth, int gridHeight, int blockSize) {
        this.gridWidth = gridWidth;
        this.gridHeight = gridHeight;
        this.blockSize = blockSize;
    }

    // Function: Draw the grid
    @Override
    public void draw(Canvas canvas, Paint paint, int blockSize) {
        paint.setColor(Color.argb(255, 0, 0, 0)); // Black color for grid lines
        // Draw the vertical lines
        for (int i = 0; i < gridWidth; i++) {
            canvas.drawLine(blockSize * i, 0, blockSize * i, gridHeight * blockSize, paint);
        }
        // Draw the horizontal lines
        for (int i = 0; i < gridHeight; i++) {
            canvas.drawLine(0, blockSize * i, gridWidth * blockSize, blockSize * i, paint);
        }
    }
}
