#include "artist.h"
#include "Listener.h"
#include <random>
#include "menu.h"
#include <string>
#include <iomanip>
#include <algorithm>
#include <vector>
#include "myvector.h"
using namespace std;

//СДЕЛАТЬ РЕДАКТИРОВАНИЕ ПЕРЕД СДАЧЕЙ, ЧТОБЫ ХОТЬ НЕ СИЛЬНО ПАЛИТЬСЯ

const int c_iMenuSize{6};
MyVector<Artist*>  artistList;
MyVector<Song*> songList;
MyVector<Listener*> userList;

//доделано
//Artist generate_random_artist()
//{
//    string strings[5];
//    int ints[3];
//    for (int i{};i<3;++i)
//    {
//        ints[i] = rand();
//    }
//    for (int i{};i<5;++i)
//    {
//        for (int j{};j<10;++j)
//        {
//            strings[i].push_back(rand()%26+'a');
//        }
//    }
//    //    UserSettings temp{strings[0],strings[1],ints[0],strings[2],strings[3]};
//    UserSettings temp{"Alex","Merser",25,"alpha","beta"};
//    Artist art = Artist(temp);
//    return art;
//}

void initialize()
{
    {
        {
            Artist *temp = new Artist;
            temp->setUserName("Alex");
            temp->setUserLastName("Merser");
            temp->setUserAge(20);
            temp->setUserLogin("Alek");
            temp->setUserPassword("asd");
            artistList.push_back(temp);
        }
        {
            Artist *temp = new Artist;
            temp->setUserName("John");
            temp->setUserLastName("Smith");
            temp->setUserAge(19);
            temp->setUserLogin("Jonny");
            temp->setUserPassword("qwerty");
            artistList.push_back(temp);
        }
        {
            Artist *temp = new Artist;
            temp->setUserName("Edward");
            temp->setUserLastName("Jackson");
            temp->setUserAge(40);
            temp->setUserLogin("Jo");
            temp->setUserPassword("zxc");
            artistList.push_back(temp);
        }
    }
    {
        int i{0};
        {
            Song* temp = new Song;
            temp->setName("Never gonna give you up");
            temp->setAuditions(100);

            songList.push_back(temp);
            songList[i]->setAuthor(artistList[i]);
            i++;
        }
        {
            Song* temp = new Song;
            temp->setName("Never gonna let you down");
            temp->setAuditions(255);
            songList.push_back(temp);
            songList[i]->setAuthor(artistList[i]);
            i++;
        }
        {
            Song* temp = new Song;
            temp->setName("Never gonna run around and desert you");
            temp->setAuditions(42);
            songList.push_back(temp);
            songList[i]->setAuthor(artistList[i]);
            i++;
        }
    }
    {
        int i{0};
        {
            Listener* temp = new Listener;;
            temp->setUserName("Jennifer");
            temp->setUserLastName("White");
            temp->setUserAge(143);
            temp->setUserLogin("Help");
            temp->setUserPassword("Me");
            temp->setFavSong(songList[i++]);
            userList.push_back(temp);
        }
        {

            Listener* temp = new Listener;;temp->setUserName("Jennifer");
            temp->setUserLastName("White");
            temp->setUserAge(143);
            temp->setUserLogin("Help");
            temp->setUserPassword("Me");
            temp->setFavSong(songList[i++]);
            userList.push_back(temp);}
        {
            Listener* temp = new Listener;;temp->setUserName("Jennifer");
            temp->setUserLastName("White");
            temp->setUserAge(143);
            temp->setUserLogin("Help");
            temp->setUserPassword("Me");
            temp->setFavSong(songList[i++]);
            userList.push_back(temp);
        }

    }

}
//Song generate_random_song(MyVector<Artist> &arts)
//{
//    string strings[5];
//    int ints[3];
//    for (int i{};i<3;++i)
//    {
//        ints[i] = rand();
//    }
//    for (int i{};i<5;++i)
//    {
//        for (int j{};j<10;++j)
//        {
//            strings[i].push_back(rand()%26+'a');
//        }
//    }
////    UserSettings temp{strings[0],strings[1],ints[0],strings[2],strings[3]};
//    Song art = Song("Good song",ints[0]);
//    art.setAuthor(&(arts[rand()%arts.size()]));
//    return art;

//}

//Listener generate_random_user(MyVector<Artist>& arts)
//{
//    string strings[5];
//    int ints[3];
//    for (int i{};i<3;++i)
//    {
//        ints[i] = rand();
//    }
//    for (int i{};i<5;++i)
//    {
//        for (int j{};j<10;++j)
//        {
//            strings[i].push_back(rand()%26+'a');
//        }
//    }
////    UserSettings temp{strings[0],strings[1],ints[0],strings[2],strings[3]};
//        UserSettings temp{"Alex","Merser",25,"alpha","beta"};
//    Listener art = Listener(temp);
//    return art;

//}

template<typename T>
void sort_func_menu(MyVector<T*>* const list)
{
//    std::sort(list->begin(),list->end());
    T* temp;
    int choice{};
    input(cin,choice,1,2,"select sorting type: 1. ascending or 2. descending (input number)");
    if (choice==1)
    {
        for (int i{}, total = list->size();i<total;++i)
        {
            for (int j{i};j<total;++j)
            {
                if ((*list)[i]>(*list)[j])
                {
                    temp = (*list)[i];
                    (*list)[i] = (*list)[j];
                    (*list)[j] = temp;
                }
            }
        }
    }
    else
    {
        for (int i{}, total = list->size();i<total;++i)
        {
            for (int j{i};j<total;++j)
            {
                if ((*list)[i]<(*list)[j])
                {
                    temp = (*list)[i];
                    (*list)[i] = (*list)[j];
                    (*list)[j] = temp;
                }
            }
        }
    }
}

template<typename T>
void find_func_menu(MyVector<T*>* const list)
{
    int id{-1};
    input(cin,id,0,INT_MAX,"Input id of element:");
    for (int i{},total=list->size();i<total;++i)
    {
        if (id==list[i]->getId()==id)
        {
            cout << list[i];
        }
    }
}


template <typename T>
void add_func_menu(MyVector<T*>* const list)
{

    T* temp = new T;
    cin >> *temp;
    list->push_back(temp);
}

template<>
void add_func_menu<Song>(MyVector<Song*>* const list)
{
    Song* temp = new Song;
    cin >> *temp;
    string title{};
    title += "Choose author (input num):\n";
    unsigned int choice{};
    for (int i{};i<artistList.size();++i)
    {
        title+= to_string(i+1)+". " + artistList[i]->getUserName() + ' ' + artistList[i]->getUserLastName() + '\n';
    }
    unsigned min{1};
    input(cin,choice,min,artistList.size(),title);

    list->push_back(temp);

    (*(list->end()-1))->setAuthor(artistList[choice-1]);

}
template<>
void add_func_menu<Listener>(MyVector<Listener*>* const list)
{
    Listener* temp = new Listener;
    cin >> *temp;
    string title{};
    title += "Choose favorite song (input num):\n";
    unsigned int choice{};
    for (int i{};i<songList.size();++i)
    {
        title+= to_string(i+1)+". " + songList[i]->getName() + '\n';
    }
    unsigned min{1};
    input(cin,choice,min,artistList.size(),title);

    list->push_back(temp);

    (*(list->end()-1))->setFavSong(songList[choice-1]);

}
template <typename T>
void print_func_menu(MyVector<T>* const list)
{
    for (int i{}, total = list->size(); i<total; ++i)
    {
        cout << *(*list)[i];
    }
}

template<typename T>
void del_func_menu(MyVector<T*>* const pList)
{
    int id{};
    bool fl{false};
    //pList->print();
    input(cin,id,0,INT_MAX,"Input id of deleted element");
    for (auto it = pList->begin();it!=pList->end();++it)
    {
        if ((*it)->getId()==id)
        {
            pList->erase(it);
            fl = true;
            break;
        }
    }
    if (!fl)
    {
        cout << "Not found\n";
    }

}
template<>
void del_func_menu<Song>(MyVector<Song*>* const pList)
{
    int id{};
    bool fl{false};
//    pList->print();
    input(cin,id,0,INT_MAX,"Input id of deleted element");
    for (auto it = pList->begin();it!=pList->end();++it)
    {
        if ((*it)->getId()==id)
        {
            (*it)->getArtist()->delSong(*it);
            pList->erase(it);
            fl = true;
            break;
        }
    }
    if (!fl)
    {
        cout << "Not found\n";
    }

}

template<typename T>
void call_menu(MyVector<T>* const crList)
{
    MenuItem<T> items[c_iMenuSize] = { MenuItem<T>("Add", add_func_menu, crList),
                                       MenuItem<T>("Print", print_func_menu, crList),
                                       MenuItem<T>("Sort", sort_func_menu, crList),
                                     MenuItem<T>("Delete", del_func_menu,crList),
                                     MenuItem<T>("Find",find_func_menu,crList),
                                     MenuItem<T>("Chenge",change_func_menu,crList)};

    Menu<T> ArtMenu = Menu<T>("Menu", items, c_iMenuSize);
    ArtMenu.run();
}

//в процессе






void main_menu(MyVector<Artist*>* const crArtistList, MyVector<Listener*>* const crUserList,  MyVector<Song*>* const crSongList)
{
    int choice = -1;
    while (choice)
    {

        input(cin,choice,0,3,"Choose menu:\n1. Artists\n2. Users\n3. Songs\n0. Exit");
        switch (choice)
        {
        case 1:
        {
            call_menu(crArtistList);
            break;
        }
        case 2:
        {
            call_menu(crUserList);
            break;
        }
        case 3:
        {
            call_menu(crSongList);
            break;
        }
        default:
        {
//            call_menu(crArtistList);
            break;
        }

//        case 2: callMenu(userlist); break;
//        case 3: callMenu(songlist); break;
        };
    }
}

int main()
{
    srand(0);
    initialize();

    main_menu(&artistList,&userList, &songList);

    return 0;
}
