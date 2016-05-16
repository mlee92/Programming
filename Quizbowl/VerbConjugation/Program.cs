// Decompiled with JetBrains decompiler
// Type: LatinVerbParse.Program
// Assembly: LatinVerbParse, Version=1.0.0.0, Culture=neutral, PublicKeyToken=null
// MVID: 33EF6563-C1C1-4E39-8A8D-9F6FFCC0691B
// Assembly location: C:\Users\Michael\Downloads\Verb Conjugation Program\Debug\LatinVerbParse.exe

using System;
using System.IO;
using System.Threading;

namespace LatinVerbParse
{
  internal class Program
  {
    private static void Main(string[] args)
    {
      Random random = new Random();
      Program.LoadDictionary();
      int latency = Program.GetLatency();
      Console.WriteLine("Press any key for a conjugation prompt");
      while (!Console.ReadKey().Equals((object) ' '))
      {
        int[] numArray = Program.Retrieve();
        int index = random.Next(1, Common.VerbDictionary.Count);
        string str = Common.VerbDictionary[index];
        Console.WriteLine();
        Console.WriteLine("For the Verb: " + str);
        Console.Write("Give the ");
        if (numArray[0] != 10)
        {
          Console.Write(Common.Persons[numArray[0]] + " ");
          Thread.Sleep(latency);
        }
        if (numArray[1] != 10)
        {
          Console.Write(Common.Number[numArray[1]] + " ");
          Thread.Sleep(latency);
        }
        if (numArray[2] != 10)
        {
          Console.Write(Common.Tense[numArray[2]] + " ");
          Thread.Sleep(latency);
        }
        if (numArray[3] != 10)
        {
          Console.Write(Common.Voice[numArray[3]] + " ");
          Thread.Sleep(latency);
        }
        if (numArray[4] != 10)
          Console.Write(Common.Mood[numArray[4]] + " ");
        Console.WriteLine();
      }
    }

    private static int[] Retrieve()
    {
      Random random = new Random();
      int num1 = random.Next(0, 5);
      int num2 = 10;
      int num3 = 10;
      int num4 = 10;
      int num5;
      if (num1 == 2)
      {
        num2 = random.Next(1, 3);
        num3 = random.Next(0, 2);
        num5 = random.Next(0, 2);
        if (num2 == 1)
          num4 = random.Next(0, 2);
        else if (num2 == 2)
          num4 = 1;
      }
      else if (num1 == 3)
      {
        num4 = random.Next(0, 3);
        num5 = random.Next(0, 2);
      }
      else if (num1 == 4)
      {
        num5 = random.Next(0, 2);
        switch (num5)
        {
          case 0:
            num4 = random.Next(0, 2);
            break;
          case 1:
            num4 = random.Next(1, 3);
            break;
        }
      }
      else
      {
        num2 = random.Next(0, 3);
        num3 = random.Next(0, 2);
        num5 = random.Next(0, 2);
        num4 = random.Next(0, 6);
      }
      return new int[5]
      {
        num2,
        num3,
        num4,
        num5,
        num1
      };
    }

    private static void LoadDictionary()
    {
      try
      {
        using (StreamReader streamReader = new StreamReader("Dictionary.txt"))
        {
          string[] strArray = streamReader.ReadToEnd().Split(',');
          for (int index = 0; index < strArray.Length - 1; ++index)
            Common.VerbDictionary.Add(index + 1, strArray[index + 1]);
        }
      }
      catch (Exception ex)
      {
        Console.WriteLine((object) ex);
      }
    }

    private static int GetLatency()
    {
      try
      {
        using (StreamReader streamReader = new StreamReader("Latency.txt"))
          return Convert.ToInt32(streamReader.ReadToEnd());
      }
      catch (Exception ex)
      {
        Console.WriteLine((object) ex);
        return 500;
      }
    }
  }
}
