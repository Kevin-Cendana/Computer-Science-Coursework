package com.gamecodeschool.subhunter;

import android.content.Context;
import android.graphics.Bitmap;
import android.graphics.Canvas;
import android.graphics.Color;
import android.graphics.Paint;
import android.widget.ImageView;

import java.util.List;

public class GameView {
    private ImageView imageView;
    private Bitmap blankBitmap;
    private Canvas canvas;
    private Paint paint;
    private List<Drawable> drawables;
    private Player player;
    private Shot shot;
    private Submarine submarine;
    int blockSize;


    // Constructor
    public GameView(ImageView imageView, Context context, List<Drawable> drawables,
                    Player player, Submarine submarine, Shot shot,
                    int screenWidth, int screenHeight,  int blockSize) {
        this.imageView = imageView;
        this.drawables = drawables;
        this.blockSize = blockSize;
        this.player = player;
        this.shot = shot; // Default shot, not on screen
        this.submarine = submarine; // Default submarine, not on screen

        // Initialize bitmap, canvas, and paint
        blankBitmap = Bitmap.createBitmap(screenWidth, screenHeight, Bitmap.Config.ARGB_8888);
        canvas = new Canvas(blankBitmap);
        paint = new Paint();

        // Set the bitmap as the content of this ImageView
        this.imageView.setImageBitmap(blankBitmap);
    }

    // Getters and Setters
    public ImageView getImageView() {
        return imageView;
    }

    public void setImageView(ImageView imageView) {
        this.imageView = imageView;
    }

    public Bitmap getBlankBitmap() {
        return blankBitmap;
    }

    public void setBlankBitmap(Bitmap blankBitmap) {
        this.blankBitmap = blankBitmap;
    }

    public Canvas getCanvas() {
        return canvas;
    }

    public void setCanvas(Canvas canvas) {
        this.canvas = canvas;
    }

    public Paint getPaint() {
        return paint;
    }

    public void setPaint(Paint paint) {
        this.paint = paint;
    }

    public List<Drawable> getDrawables() {
        return drawables;
    }

    public void setDrawables(List<Drawable> drawables) {
        this.drawables = drawables;
    }

    // Function: Draw a Drawable object
    public void draw() {
        // Clear the canvas
        canvas.drawColor(Color.WHITE);

        // Draw each drawable (Player, Submarine, Shot, Grid)
        for (Drawable drawable : drawables) {
            drawable.draw(canvas, paint, blockSize);
        }

        // Draw score
        drawScore(player.getShotsTaken(), submarine.getDistanceFromShot(), blockSize);

        // Update the ImageView with the modified Bitmap
        imageView.setImageBitmap(blankBitmap);
    }

    // Function: Draw the game's text
    public void drawScore(int shotCount, int distanceFromSub, int blockSize) {
        // Set the paint color and text size
        paint.setTextSize(blockSize * 2);
        paint.setColor(Color.argb(255, 0, 0, 255));

        // If the distance is greater than 0, show it. Else, show nothing.
        String distanceText = distanceFromSub > 0 ? String.valueOf(distanceFromSub) : "";

        // Draw the text
        canvas.drawText(
                "Shots Taken: " + shotCount +
                        "  Distance: " + distanceText,
                blockSize, blockSize * 1.75f,
                paint);

    }
}
