using System;
using System.Collections.Generic;

public class DoubleLinear
{
public static int DblLinear (int n)
{
SortedSet<int> sequence = new SortedSet<int>();
sequence.Add(1);

    for (int i = 0; i < n; i++) 
    {
        int x = sequence.Min;
        sequence.Remove(x);
        sequence.Add(2 * x + 1);
        sequence.Add(3 * x + 1);
    }

    return sequence.Min;
}
}