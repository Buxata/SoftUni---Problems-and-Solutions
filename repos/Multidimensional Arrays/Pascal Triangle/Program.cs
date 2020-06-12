using System;
using System.Collections.Generic;

namespace Pascal_Triangle
{
    class Program
    {
        static void Main(string[] args)
        {
            int triangleLevel = int.Parse(Console.ReadLine());

            long[] triangleFull = new long[triangleLevel+2];
            for (int i = 0; i < triangleLevel + 2; i++ ) triangleFull[i] = 0;
            triangleFull[0] = 1;
            Console.WriteLine("1 ");
            for (int i = 1; i < triangleLevel; i++ )
            {
                long[] triangle = new long[i];
                for (int n = 0; n < i; n++)
                {
                    triangle[n] = triangleFull[n] + triangleFull[n + 1];    
                }
                Console.Write("1 ");
                for (int n = 0; n < i; n++)
                {
                    Console.Write($"{triangle[n]} ");
                    triangleFull[n + 1] = triangle[n];
                }
                Console.WriteLine();
            }
            
        }
    }
}
