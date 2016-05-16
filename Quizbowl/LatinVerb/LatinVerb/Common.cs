using System.Collections.Generic;

namespace LatinVerb
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
