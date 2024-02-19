// Player.java

package com.gamecodeschool.subhunter;

public class Player {
    private int shotsTaken;
    private int horizontalTouched;
    private int verticalTouched;

    // Constructor
    public Player() {
        this.shotsTaken = 0;
        this.horizontalTouched = -100; // Initial value indicating no shot
        this.verticalTouched = -100; // Initial value indicating no shot
    }

    // Getters and Setters
    public int getShotsTaken() {return shotsTaken;}
    public void setShotsTaken(int shotsTaken) {this.shotsTaken = shotsTaken;}
    public void incrementShotsTaken() {this.shotsTaken++;}
    public float getHorizontalTouched() {return horizontalTouched;}
    public void setHorizontalTouched(int horizontalTouched) {this.horizontalTouched = horizontalTouched;}
    public float getVerticalTouched() {return verticalTouched;}
    public void setVerticalTouched(int verticalTouched) {this.verticalTouched = verticalTouched;}
}
