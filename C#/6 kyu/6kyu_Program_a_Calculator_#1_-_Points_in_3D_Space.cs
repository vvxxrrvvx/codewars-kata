using System;

public class Point
{
    public double X { get; }
    public double Y { get; }
    public double Z { get; }

    public Point(double x, double y, double z)
    {
        X = x;
        Y = y;
        Z = z;
    }    
    public static Point GetOrigin()
    {
        return new Point(0, 0, 0);
    }    
    public double GetDistanceFromOrigin()
    {
        return Math.Sqrt(X * X + Y * Y + Z * Z);
    }    
    public double GetDistanceFromPoint(Point otherPoint)
    {
        double dx = X - otherPoint.X;
        double dy = Y - otherPoint.Y;
        double dz = Z - otherPoint.Z;

        return Math.Sqrt(dx * dx + dy * dy + dz * dz);
    }
}