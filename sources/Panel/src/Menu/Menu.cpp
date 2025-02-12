// 2025/02/11 20:24:55 (c) Aleksandr Shevchenko e-mail : Sasha7b9@tut.by
#include "defines.h"
#include "Menu/Menu.h"
#include "Menu/Pages/Pages.h"


namespace Menu
{
    Page *opened_page = PageMain::self;
}


Page *Menu::OpenedPage()
{
    return opened_page;
}


void Menu::SetOpenedPage(Page *page)
{
    opened_page = page;

    page->OnEventPage();
}


void Menu::Init()
{

}


void Menu::Input::Update()
{

}


void Menu::Input::SetFuncUpdate(void (*)())
{

}


void Menu::Input::FuncUpdate()
{

}


void Menu::Input::FuncEmptyUpdate()
{

}
