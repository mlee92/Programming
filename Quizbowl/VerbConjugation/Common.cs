// Decompiled with JetBrains decompiler
// Type: LatinVerbParse.Common
// Assembly: LatinVerbParse, Version=1.0.0.0, Culture=neutral, PublicKeyToken=null
// MVID: 33EF6563-C1C1-4E39-8A8D-9F6FFCC0691B
// Assembly location: C:\Users\Michael\Downloads\Verb Conjugation Program\Debug\LatinVerbParse.exe

using System.Collections.Generic;

namespace LatinVerbParse
{
  internal class Common
  {
    public static Dictionary<int, string> VerbDictionary = new Dictionary<int, string>();
    public static string[] Persons = new string[3]
    {
      "1st Person",
      "2nd Person",
      "3rd Person"
    };
    public static string[] Number = new string[2]
    {
      "Singular",
      "Plural"
    };
    public static string[] Tense = new string[6]
    {
      "Present",
      "Future",
      "Perfect",
      "Imperfect",
      "Pluperfect",
      "Future Perfect"
    };
    public static string[] Voice = new string[2]
    {
      "Active",
      "Passive"
    };
    public static string[] Mood = new string[5]
    {
      "Indicative",
      "Subjunctive",
      "Imperative",
      "Infinitive",
      "Participle"
    };
  }
}
