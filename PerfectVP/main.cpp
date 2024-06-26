#include "artist.h"
#include "regularuser.h"
#include <random>
#include "menu.h"
#include <string>
#include <iomanip>
#include <vector>
using namespace std;

const int c_iMenuSize{3};
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
    Artist art = Artist(strings[0],strings[1],ints[0],strings[2],strings[3]);
    return art;

}
template<typename T>
void sort(vector<T> list)
{
    T temp;
    for (int i{}, total = list.size();i<total;++i)
    {
        for (int j{i};j<total;++j)
        {
            if (list[i]<list[j])
            {
                temp = list[i];
                list[i] = list[j];
                list[j] = temp;
            }
        }
    }
}


//в процессе
void del(Artist *list, int size, Artist *deleted) /// <<@todo unused parametr
{
    for (int i{};i<size;++i)
    {
        list[i]; /// <<@todo statement has no effect
    }
}

//vector<Song*> chooseSongs()
//{

//    int choice{-1};
//    vector<Song*> choiced;
//    while (choice)
//    {
//        cout << "Choose songs (0 = exit):" << endl;
//    for (int i{}, total = SONGLIST.size();i<total;++i)
//    {
//        cout << i+1 << ". " << SONGLIST[i] << endl;
//    };
//    cin >> choice;
//    if (choice>0)
//        choiced.push_back(SONGLIST[choice-1]);
//    };
//    return choiced;
//}
template <typename T>
void add_func_menu(vector<T> list)
{
    //    Artist(string name, string surname, int age, string login, string password,Song* songs, int auditions);
    T temp;
    cin >> temp;
    list.push_back(temp);
}

template <typename T>
void print_func_menu(vector<T> list)
{
    for (int i{}, total = list.size(); i<total; ++i)
    {
        cout << list[i];
    }
}

template<typename T>
void call_menu(const vector<T>& crList)
{
    MenuItem<T> items[c_iMenuSize] = { MenuItem<T>("Add", add_func_menu, crList),
                                       MenuItem<T>("Print", print_func_menu, crList),
                                       MenuItem<T>("Sort", sort, crList) };

    Menu<T> ArtMenu = Menu<T>("Menu", items, c_iMenuSize);
    ArtMenu.run();
}

//void call_menu(vector<Artist>& list)
//{
//    MenuItem<Artist> items[c_iMenuSize] = {MenuItem<Artist>("Add",add_func_menu,list),MenuItem<Artist>("Print",print_func_menu,list),MenuItem<Artist>("Sort",sort,list)};
//    Menu<Artist> ArtMenu = Menu<Artist>("Menu",items,c_iMenuSize);
//    ArtMenu.run();
//}
//void UsersMenu(vector<RegularUser> list)
//{
//    MenuItem items[MENUSIZE] = {MenuItem("Add",addFuncMenu,list),MenuItem("Print",printFuncMenu,list),MenuItem("Sort",sort,list)};
//    Menu UserMenu = Menu("Menu",items,MENUSIZE);
//    UserMenu.run();
//}
//void SongsMenu(vector<Song> list)
//{
//    MenuItem items[MENUSIZE] = {MenuItem("Add",addFuncMenu,list),MenuItem("Print",printFuncMenu,list),MenuItem("Sort",sort,list)};
//    Menu SongMenu = Menu("Menu",items,MENUSIZE);
//    SongMenu.run();
//}

void main_menu(const vector<Artist>& crArtistlist, vector<RegularUser> userlist, vector<Song> songlist)
{
    int choice = -1;
    while (choice)
    {
        cout << "Choose menu:" << endl;
        cout << "1. Artists" << endl << "2. Users" << endl << "3. Songs" << endl << "0. Exit program" << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            call_menu(crArtistlist);
            break;
        }
        default:
        {
            break;
        }

//        case 2: callMenu(userlist); break;
//        case 3: callMenu(songlist); break;
        };
    }
}

int main()
{
    srand(17);
    vector<Artist> artistList;
    vector<Song> songList;
    vector<RegularUser> userList;

//    MenuItem mainMenuItems[3] = {MenuItem("Artists",ArtistsMenu(),ARTISTLIST),MenuItem("Users",UsersMenu,USERLIST),MenuItem("Songs",SongsMenu,SONGLIST)};

//    Menu mainMenu("Main menu",mainMenuItems);
    for (int i{};i<c_iTestSize;++i)
    {
        artistList.push_back(generate_random_artist());
    };

    main_menu(artistList,userList, songList);

    return 0;
}
