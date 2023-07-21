using System;
using System.Text;

public static class Base64Utils
{
    public static string ToBase64(string s)
    {
        byte[] bytes = Encoding.UTF8.GetBytes(s);
        return Convert.ToBase64String(bytes);
    }

    public static string FromBase64(string s)
    {
        byte[] bytes = Convert.FromBase64String(s);
        return Encoding.UTF8.GetString(bytes);
    }
}