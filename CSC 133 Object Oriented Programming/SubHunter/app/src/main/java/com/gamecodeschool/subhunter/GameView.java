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
    int blockSize;



    // Constructor
    public GameView(Context context, int screenWidth, int screenHeight, List<Drawable> drawables, int blockSize) {
        this.imageView = imageView;
        this.drawables = drawables;
        this.blockSize = blockSize;


        // Initialize bitmap, canvas, and paint
        blankBitmap = Bitmap.createBitmap(screenWidth, screenHeight, Bitmap.Config.ARGB_8888);
        canvas = new Canvas(blankBitmap);
        paint = new Paint();

        // Set the bitmap as the content of this ImageView
        this.imageView.setImageBitmap(blankBitmap);
    }

    // Getters and Setters
    public ImageView getImageView() { return imageView; }
    public void setImageView(ImageView imageView) { this.imageView = imageView; }
    public Bitmap getBlankBitmap() { return blankBitmap; }
    public void setBlankBitmap(Bitmap blankBitmap) { this.blankBitmap = blankBitmap; }
    public Canvas getCanvas() { return canvas; }
    public void setCanvas(Canvas canvas) { this.canvas = canvas; }
    public Paint getPaint() { return paint; }
    public void setPaint(Paint paint) { this.paint = paint; }
    public List<Drawable> getDrawables() { return drawables; }
    public void setDrawables(List<Drawable> drawables) { this.drawables = drawables; }

    // Function: Draw a Drawable object
    public void draw() {
        // Clear the canvas
        canvas.drawColor(Color.WHITE);

        // Draw each drawable
        for (Drawable drawable : drawables) {
            drawable.draw(canvas, paint, blockSize);
        }

        // Invalidate to request a redraw
        //invalidate();
    }
}
