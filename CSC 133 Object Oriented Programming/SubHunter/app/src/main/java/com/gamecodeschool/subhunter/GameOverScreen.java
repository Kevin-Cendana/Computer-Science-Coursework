package com.gamecodeschool.subhunter;

import android.graphics.Canvas;
import android.graphics.Color;
import android.graphics.Paint;

public class GameOverScreen implements Drawable {
    private boolean isVisible = false;

    public void show() {
        this.isVisible = true;
    }

    public void hide() {
        this.isVisible = false;
    }

    public boolean getIsVisible() {return this.isVisible; };
    @Override
    public void draw(Canvas canvas, Paint paint, int blockSize) {
        // If already visible, return
        if (!isVisible) {
            return;
        }

        // Wipe the screen with a red color
        canvas.drawColor(Color.argb(255, 255, 0, 0));

        // Set the paint color for the "BOOM!" text
        paint.setColor(Color.WHITE);
        paint.setTextSize(blockSize * 10);

        // Calculate the position to start the text, so it's somewhat centered
        int xPos = blockSize * 5;
        int yPos = blockSize * 14;

        canvas.drawText("BOOM!", xPos, yPos, paint);

        // Draw some text to prompt restarting
        paint.setTextSize(blockSize * 2);
        canvas.drawText("Take a shot to start again",
                blockSize * 8,
                blockSize * 18, paint);

        // todo - Currently resets the visibility if you want "BOOM!" to only show once per hit
        //hide();
    }
}
