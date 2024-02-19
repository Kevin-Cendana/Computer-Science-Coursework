// Player.java

package com.gamecodeschool.subhunter;

public class Player {
    private int shotsTaken;

    // Constructor
    public Player() {
        this.shotsTaken = 0;
    }

    // Getters and Setters
    public int getShotsTaken() {return shotsTaken;}
    public void setShotsTaken(int shotsTaken) {this.shotsTaken = shotsTaken;}
    public void incrementShotsTaken() {this.shotsTaken++;}

}
