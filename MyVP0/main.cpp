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

const int c_iMenuSize{4};
const int c_iTestSize{10};


//доделано
Artist generate_random_artist()
{
    string strings[5];
    int ints[3];
    for (int i{};i<3;++i)
    {
        ints[i] = rand();
    }
    for (int i{};i<5;++i)
    {
        for (int j{};j<10;++j)
        {
            strings[i].push_back(rand()%26+'a');
        }
    }
//    UserSettings temp{strings[0],strings[1],ints[0],strings[2],strings[3]};
        UserSettings temp{"Alex","Merser",25,"alpha","beta"};
    Artist art = Artist(temp);
    return art;
}

Song generate_random_song(MyVector<Artist> &arts)
{
    string strings[5];
    int ints[3];
    for (int i{};i<3;++i)
    {
        ints[i] = rand();
    }
    for (int i{};i<5;++i)
    {
        for (int j{};j<10;++j)
        {
            strings[i].push_back(rand()%26+'a');
        }
    }
//    UserSettings temp{strings[0],strings[1],ints[0],strings[2],strings[3]};
    Song art = Song("Good song",ints[0]);
    art.setAuthor(&(arts[rand()%arts.size()]));
    return art;

}

Listener generate_random_user(MyVector<Artist>& arts)
{
    string strings[5];
    int ints[3];
    for (int i{};i<3;++i)
    {
        ints[i] = rand();
    }
    for (int i{};i<5;++i)
    {
        for (int j{};j<10;++j)
        {
            strings[i].push_back(rand()%26+'a');
        }
    }
//    UserSettings temp{strings[0],strings[1],ints[0],strings[2],strings[3]};
        UserSettings temp{"Alex","Merser",25,"alpha","beta"};
    Listener art = Listener(temp);
    art.setFavoriteArtist(&arts[rand()%arts.size()]);
    return art;

}

template<typename T>
void sort_func_menu(MyVector<T>* const list)
{
//    std::sort(list->begin(),list->end());
    T temp;
    int choice{};
    input(cin,choice,1,2,"select sorting type: 1. ascending or 2. descending (input number)");
    if (choice==1)
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
    else
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
}

template<typename T>
void find_func_menu(MyVector<T>* const list)
{
    int id{-1};
    input(cin,id,0,INT_MAX,"Input id of element:");
    for (int i{},total=list->size();i<total;++i)
    {
        if (id==list[i].getId()==id)
        {
            cout << list[i];
        }
    }
}


template <typename T>
void add_func_menu(MyVector<T>* const list)
{

    T temp;
    cin >> temp;
    list->push_back(temp);
}



template <typename T>
void print_func_menu(MyVector<T>* const list)
{
    for (int i{}, total = list->size(); i<total; ++i)
    {
        cout << (*list)[i];
    }
}

template<typename T>
void del_func_menu(MyVector<T>* const pList)
{
    int id{};
    input(cin,id,0,INT_MAX,"Input id of deleted element");
    for (auto it = pList->begin();it!=pList->end();++it)
    {
        if ((*it).getId()==id)
        {
            pList->erase(it);
        }
    }
//    for (int i{};i<pList->size();++i)
//    {
//        if (pList[i].getId()==id)
//        {
//            pList->erase()
//        }
//    }

}

template<typename T>
void call_menu(MyVector<T>* const crList)
{
    MenuItem<T> items[c_iMenuSize] = { MenuItem<T>("Add", add_func_menu, crList),
                                       MenuItem<T>("Print", print_func_menu, crList),
                                       MenuItem<T>("Sort", sort_func_menu, crList),
                                     MenuItem<T>("Delete", del_func_menu,crList)};

    Menu<T> ArtMenu = Menu<T>("Menu", items, c_iMenuSize);
    ArtMenu.run();
}

//в процессе






void main_menu(MyVector<Artist>* const crArtistList, MyVector<Listener>* const crUserList,  MyVector<Song>* const crSongList)
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
    MyVector<Artist>  artistList;
    MyVector<Song> songList;
    MyVector<Listener> userList;

    for (int i{};i<c_iTestSize;++i)
    {
        artistList.push_back(generate_random_artist());
    };
    for (int i{};i<c_iTestSize;++i)
    {
        songList.push_back(generate_random_song(artistList));
    };
    for (int i{};i<c_iTestSize;++i)
    {
        userList.push_back(generate_random_user(artistList));
    };

    main_menu(&artistList,&userList, &songList);

    return 0;
}
