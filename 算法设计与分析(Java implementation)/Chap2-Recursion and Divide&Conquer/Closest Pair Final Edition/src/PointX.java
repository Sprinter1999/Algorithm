public class PointX implements Comparable {
    int enodebid;
    double longitude, latitude;

    public PointX() {
        this.enodebid = 0;
        this.longitude = 0.0;
        this.latitude = 0.0;
    }

    public PointX(int enodebid, double longitude, double latitude) {
        this.enodebid = enodebid;
        this.longitude = longitude;
        this.latitude = latitude;
    }

    public int compareTo(Object o) {
        // TODO Auto-generated method stub
        double ox = ((PointX) o).latitude;
        if (this.latitude < ox) return -1;
        if (this.latitude == ox) return 0;
        return 1;
    }
    public boolean equals(Object o) {
        return this.latitude == ((PointY) o).latitude;
    }
}