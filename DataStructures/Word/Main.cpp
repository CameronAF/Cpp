#include "Word.h"

int main()
{
	Word you;
	cout<<"Testing the default constructor and printing empty word\n";
	cout<<you<<endl<<endl;
	
	Word me("123abc345abc129012");
	cout<<"Testing the explicit-value constructor\n";
	cout<<me<<endl<<endl;

	Word them = me;
	cout<<"Testing the copy constructor\n";
	cout<< them <<" = "<< me << endl<<endl;


	cout<<"Testing length\n";
	cout<<"The length of me is "<<me.Length()<<endl;
	cout<<"The length of them is "<<them.Length()<<endl;
	cout<<"The length of you is "<<you.Length()<<endl<<endl;


	cout<<"Testing Insert by inserting me into you at position 0\n";
	you.Insert(me,0);
	cout<<"The word you is "<<you<<endl<<endl;

	Word us;
	us = "abc";
	cout<<"Testing operator= by assignment the value of \"abc\" to use\n";
	cout<<us<<endl<<endl;

	Word word1, word2, word3;
	word1 = "ABC123XYZ";
	cout<<"Testing overloaded operator= with chaining by assignment the value of \"ABC123XYZ\" to use\n";
	word3=word2=word1;
	cout<<"word3 is "<<word3<<", word2 is "<<word2<<" and word1 is "<<word1<<endl;
	cout<<"Testing overloaded operator= with chaining by assignment the value of word1, \"ABC123XYZ\", into itself \n";
	word1 = word1 = word1;
	cout<<"word1 is "<<word1<<endl<<endl;

	them.Remove(us);
	cout<<"Testing Remove by removing us from them \n";
	cout<<"The word them is "<<them<<endl<<endl;

	me.RemoveAll(us);
	cout<<"Testing RemoveAll by removing all occurrences of us in me \n";
	cout<<"The word me is "<<me<<endl<<endl;

	Word our, him;

	our = "XXXCCCYYY";
	us = "XXXX";
	
	cout<<"Testing IsEqual by testing to see if us is equal to our \n";
	if (our.IsEqual(us))
		cout<<"The 2 words are equal\n"<<endl;
	else
		cout<<"The 2 words are not equal\n"<<endl;
	
	cout<<"Testing SetEqual and IsEqual by setting the value of us to the value stored in our \n";
	our.SetEqual(us);
	if (our.IsEqual(us))
		cout<<"The 2 words are equal\n"<<endl;
	else
		cout<<"The 2 words are not equal\n"<<endl;
	
	Word their("abcABCDEF");
	Word yo, child;
	
	cout<<"Testing AddStrings by adding a string to the back of an empty string \n";
	cout<<"Adding to an empty word\n";
	yo.CatWords(their);
	cout<<"The value of yo is "<<yo<<endl;

	cout<<"Adding an empty word to another word by adding an empty string to a non empty string \n";
	yo.CatWords(child);
	cout<<"The value of yo is "<<yo<<endl;

	cout<<"Adding 2 words by adding us to the back of their.  Their is the current object \n";
	their.CatWords(us);
	cout<<"their followed by us is "<<their<<endl<<endl;              
	
	cout<<"you has '"<<you<<"', The length of me is "<<you.Length()<<endl;
	cout<<"me has '"<<me<<"', The length of me is "<<me.Length()<<endl;
	cout<<"them has '"<<them<<"', The length of me is "<<them.Length()<<endl;
	cout<<"us has '"<<us<<"', The length of me is "<<us.Length()<<endl;
	cout<<"word1 has '"<<word1<<"', The length of me is "<<word1.Length()<<endl;
	cout<<"word2 has '"<<word2<<"', The length of me is "<<word2.Length()<<endl;
	cout<<"word3 has '"<<word3<<"', The length of me is "<<word3.Length()<<endl;
	cout<<"our has '"<<our<<"', The length of me is "<<our.Length()<<endl;
	cout<<"him has '"<<him<<"', The length of me is "<<him.Length()<<endl;
	cout<<"their has '"<<their<<"', The length of me is "<<their.Length()<<endl;
	cout<<"yo has '"<<yo<<"', The length of me is "<<yo.Length()<<endl;
	cout<<"child has '"<<child<<"', The length of me is "<<child.Length()<<endl<<endl;
	return 0;
}