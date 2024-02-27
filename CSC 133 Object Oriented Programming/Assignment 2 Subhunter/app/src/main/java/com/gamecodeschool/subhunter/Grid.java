// Grid.java
// Draws the starting grid.

package com.gamecodeschool.subhunter;
import android.graphics.Canvas;
import android.graphics.Color;
import android.graphics.Paint;

public class Grid implements Drawable {
    private GameContext gameContext;

    // Constructor
    public Grid(GameContext gameContext) {
        this.gameContext = gameContext;
    }

    // Function: Draw the grid
    @Override
    public void draw(Canvas canvas, Paint paint, int blockSize) {
        paint.setColor(Color.argb(255, 0, 0, 0)); // Black color for grid lines
        // Draw the vertical lines
        for (int i = 0; i < gameContext.getGridWidth(); i++) {
            canvas.drawLine(blockSize * i, 0, blockSize * i, gameContext.getGridHeight() * blockSize, paint);
        }
        // Draw the horizontal lines
        for (int i = 0; i < gameContext.getGridHeight(); i++) {
            canvas.drawLine(0, blockSize * i, gameContext.getGridWidth() * blockSize, blockSize * i, paint);
        }
    }
}
