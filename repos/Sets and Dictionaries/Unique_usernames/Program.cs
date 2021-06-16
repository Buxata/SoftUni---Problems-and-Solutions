using System;
using System.Collections.Generic;

namespace Unique_usernames
{
    class Program
    {
        static void Main(string[] args)
        {
            var UserNames = new HashSet<string>();
            int n = int.Parse(Console.ReadLine());
            for (int i = 0; i < n; i++)
            {
                UserNames.Add(Console.ReadLine());
            }

            foreach (string username in UserNames)
            {
                Console.WriteLine(username);
            }
        }
    }
}
