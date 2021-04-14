/*
Task: H3
Family Name: Hasan
Given Name: Ashiq
Matriculation number: 3023634
Uni-Email: ashiq.hasan@stud.uni-due.de
Course of Studies: ISE CE
*/
#include <iostream>
#include <fstream>

using namespace std;



struct Entry{
string key;string value;
string n; /*this will stay always empty and will help us to find the whole length of the array */
};

int Hash_Function(string german_word, int p)
{
    unsigned int i=0,index_no;
    index_no=(int)german_word[0];
    while(i<german_word.length()-1)
    {
        index_no=((index_no*128+(int)german_word[i+1])%p);
        i++;
    }
return index_no;}





int element_no_in_EntryArray(Entry E[])
{
    int element_counter=0;
    while(E[element_counter].n.empty())
    {
     element_counter++;
    }
return element_counter;}



void insert_data_in_hash_table(string german_word,string english_word,Entry Dictionary_hashtable[])
{
int number_of_element_in_array;
int index_no;
number_of_element_in_array=element_no_in_EntryArray(Dictionary_hashtable);
index_no=Hash_Function(german_word,number_of_element_in_array);
int loop_counter;
for(loop_counter=0;loop_counter<number_of_element_in_array;loop_counter++)
{
    if(Dictionary_hashtable[index_no].key.empty())
    {
        Dictionary_hashtable[index_no].key=german_word;
        Dictionary_hashtable[index_no].value=english_word;
        break;
    }
    else
    {
        index_no++;
        if(index_no==number_of_element_in_array)
        {
            index_no=0;
        }
    }

}


}


void read_file_initialise_dictionary(string file_name,Entry Dictionary_hashtable[])
{
    string german_word[2]={"",""};
    string english_word[2]={"",""};
    string word="";
    bool after_semi=false;
    char c;/*this character c will be reading alphabet by alphabet */
    ifstream i;
    i.open(file_name.c_str());
    if(i.is_open())
    {
        while(!i.eof())
        {
            c=i.get();

            if(after_semi==false)
            {
             if(c==';')
            {    c=i.get();
                german_word[0]=word;
                word="";
                after_semi=true;

            }
            if(c==',')
            {
                c=i.get();
                c=i.get();
                german_word[1]=word;
                word="";

            }
            }
            else
            {
               if(c=='\n' || i.eof())
            {    c=i.get();
                english_word[0]=word;
                word="";
                insert_data_in_hash_table(german_word[0],english_word[0],Dictionary_hashtable);
                if(german_word[1]!="")
                {
                    if(english_word[1]!="")
                    {
                       insert_data_in_hash_table(german_word[1],english_word[1],Dictionary_hashtable);
                       german_word[1]="";
                       english_word[1]="";
                    }else
                    {
                        insert_data_in_hash_table(german_word[1],english_word[0],Dictionary_hashtable);
                       german_word[1]="";
                    }

                }
                after_semi=false;

            }
            if(c==','&&german_word[1]!="")
            {
                c=i.get();
                english_word[1]=word;
                word="";

            }
            }


         word=word+c;

        }
    }
    else
        {cout<<"error opening file at location ("<<file_name<<")"<<endl;}
}

void search_german_word_in_dictionary(string german_word, Entry dictionary[])
{
    int index_no=Hash_Function(german_word,element_no_in_EntryArray(dictionary));

      if(dictionary[index_no].key==german_word)
      {
          cout<<dictionary[index_no].key<<" -> "<<dictionary[index_no].value<<endl;
      }
      else
      {
          int i=1,up,down;
          up=index_no;
          down=index_no;
         while(1)
         {  up=index_no-i;
             down=index_no+i;


             if(up>-1)
             {

                 if(dictionary[up].key==german_word)
                 {
                     cout<<dictionary[up].key<<" -> "<<dictionary[up].value<<endl;break;
                 }
             }
             if(down<element_no_in_EntryArray(dictionary))
             {

                 if(dictionary[down].key==german_word)
                 {
                     cout<<dictionary[down].key<<" -> "<<dictionary[down].value<<endl;break;
                 }
             }


         if(up<=0 && down>=element_no_in_EntryArray(dictionary)-1)
         {
             cout<<" sorry not known"<<endl;break;
         }

             i++;
         }




      }

}

int main()
{
    int p;
     string german_word;
     cout<<"please input value for (prime) number p: ";
     cin>>p;
     Entry hashtable[p];
    read_file_initialise_dictionary("C:\\Users\\00\\Downloads\\berufe_professions.txt",hashtable);

  for(int i=0;i<p;i++)
  {
      cout<<i<<" "<<hashtable[i].key<<"="<<hashtable[i].value<<endl;
  }

  while(1)
  {
      cout<<"translate (0 for end):";
      cin>>german_word;
      if(german_word=="0")
      {
          break;
      }

      search_german_word_in_dictionary(german_word,hashtable);
  }

    return 0;


}
