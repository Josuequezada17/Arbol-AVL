#include "menu.hpp"

int main()
{
  Menu myMenu;
  //BTree<Song> myArbol;
  BTree<Persona> myArbol;

  myMenu.mainMenu(myArbol);

  return 0;
}
