public class PointY implements Comparable {
    int xp;
    double longitude, latitude;

    public PointY() {
        this.xp = 0;
        this.longitude = 0.0;
        this.latitude = 0.0;
    }

    public PointY(int xp, double longitude, double latitude) {
        this.xp = xp;
        this.longitude = longitude;
        this.latitude = latitude;
    }

    public int compareTo(Object o) {
        // TODO Auto-generated method stub
        double ox = ((PointY) o).longitude;
        if (this.longitude < ox) return -1;
        if (this.longitude == ox) return 0;
        return 1;
    }
    public boolean equals(Object o) {
        return this.longitude == ((PointY) o).longitude;
    }
}