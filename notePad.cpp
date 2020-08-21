#include <windows.h>
#include <iostream>

#define ID_TEXT 0
#define ID_QUIT 1
#define ID_NEW 2
#define ID_UNDO 3
#define ID_REDO 4
#define ID_CUT 5
#define ID_COPY 10
#define ID_PASTE 11
#define ID_SELECT_ALL 12
#define ID_PRINT 13
#define ID_HELP 14
#define ID_CHANGE_LOG 15
#define ID_FEEDBACK 16

#define HotkeyDone 17
#define HotkeyTodo 18

const char g_szClassName[] = "newWindowClass";
using namespace std;

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
  switch(msg) {
    case WM_CREATE: {
      HMENU menubar = CreateMenu();
      HMENU file = CreateMenu();
      HMENU edit = CreateMenu();
      HMENU view = CreateMenu();
      HMENU help = CreateMenu();

      AppendMenu(menubar, MF_POPUP, (UINT_PTR) file, "File");
      AppendMenu(menubar, MF_POPUP, (UINT_PTR) edit, "Edit");
      AppendMenu(menubar, MF_POPUP, (UINT_PTR) view, "View");
      AppendMenu(menubar, MF_POPUP, (UINT_PTR) help, "Help");

      AppendMenu(file, MF_STRING, ID_QUIT, "Quit");
      AppendMenu(file, MF_SEPARATOR, 0, NULL);
      AppendMenu(file, MF_STRING, ID_NEW, "New");

      AppendMenu(edit, MF_STRING, ID_UNDO, "Undo");
      AppendMenu(edit, MF_STRING, ID_REDO, "Redo");
      AppendMenu(edit, MF_SEPARATOR, 0, NULL);
      AppendMenu(edit, MF_STRING, ID_CUT, "Cut");
      AppendMenu(edit, MF_STRING, ID_COPY, "Copy");
      AppendMenu(edit, MF_STRING, ID_PASTE, "Paste");
      AppendMenu(edit, MF_SEPARATOR, 0, NULL);
      AppendMenu(edit, MF_STRING, ID_SELECT_ALL, "Select all");

      AppendMenu(view, MF_STRING, ID_PRINT, "Print");

      AppendMenu(help, MF_STRING, ID_HELP, "Notes help");
      AppendMenu(help, MF_STRING, ID_CHANGE_LOG, "Updates");
      AppendMenu(help, MF_STRING, ID_FEEDBACK, "Give feedback");

      CreateWindow("Edit", "", WS_VISIBLE|WS_CHILD|ES_MULTILINE|ES_WANTRETURN,10,10,1000,1000,hwnd,(HMENU) ID_TEXT, NULL, NULL);
      RegisterHotKey(NULL, HotkeyDone, MOD_ALT, 0x64);
      RegisterHotKey(NULL, HotkeyDone, MOD_ALT, 0x74);

      SetMenu(hwnd, menubar);

      break;
    }

    case WM_CLOSE:
      DestroyWindow(hwnd);
      break;
    case WM_DESTROY:
      PostQuitMessage(0);
      break;
    case WM_COMMAND:
      switch(LOWORD(wParam)) {
        case ID_QUIT:
          SendMessage(hwnd, WM_CLOSE, 0, 0);
          break;
        case ID_NEW:
          CreateWindowEx(WS_EX_CLIENTEDGE, g_szClassName, "Notepad--", WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, 1080, 720, NULL, NULL, NULL, NULL);
          break;
        case ID_UNDO:
          cout << "Undo" << endl;
          break;
        case ID_REDO:
          cout << "Redo" << endl;
          break;
        case ID_CUT:
          cout << "Cut" << endl;
          break;
        case ID_COPY:
          cout << "Copy" << endl;
          break;
        case ID_PASTE:
          cout << "Paste" << endl;
          break;
        case ID_SELECT_ALL:
          cout << "Select all" << endl;
          break;
        case ID_PRINT:
          cout << "Print" << endl;
          break;
        case ID_HELP:
          cout << "Help" << endl;
          break;
        case ID_CHANGE_LOG:
          ShellExecute(NULL, "open", "https://forms.gle/zYpsfNdqJZW2pVzU6", NULL, NULL, SW_SHOWNORMAL);
          break;
        case ID_FEEDBACK:
          ShellExecute(NULL, "open", "https://forms.gle/zYpsfNdqJZW2pVzU6", NULL, NULL, SW_SHOWNORMAL);
          break;
        case HotkeyDone:
          MessageBox(hwnd, "Sorry! I had a ton of trouble implementing hotkeys into this program, I'll probably be re-writing this in the future.", NULL, MB_OK);
          break;
        case HotkeyTodo:
          MessageBox(hwnd, "Sorry! I had a ton of trouble implementing hotkeys into this program, I'll probably be re-writing this in the future.", NULL, MB_OK);
          break;
    }
    break;

    default:
      return DefWindowProc(hwnd, msg, wParam, lParam);
  }
  return 0;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
  LPSTR lpCmdLine, int nCmdShow) {
    WNDCLASSEX wc;
    HWND hwnd;
    MSG Msg;

    //Step 1: Registering the Window Class
    wc.cbSize = sizeof(WNDCLASSEX);
    wc.style = 0;
    wc.lpfnWndProc = WndProc;
    wc.cbClsExtra = 0;
    wc.cbWndExtra = 0;
    wc.hInstance = hInstance;
    wc.hIcon = LoadIcon(NULL, "notepad--.ico");
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW+1);
    wc.lpszMenuName = NULL;
    wc.lpszClassName = g_szClassName;
    wc.hIconSm = LoadIcon(NULL, "notepad--.ico");

    if(!RegisterClassEx(&wc)) {
      MessageBox(NULL, "Window Registration Failed!", "Error!",
      MB_ICONEXCLAMATION | MB_OK);
      return 0;
    }

    // Step 2: Creating the Window
    hwnd = CreateWindowEx(WS_EX_CLIENTEDGE, g_szClassName, "Notepad--", WS_OVERLAPPEDWINDOW|ES_MULTILINE|ES_WANTRETURN , CW_USEDEFAULT, CW_USEDEFAULT, 1080, 720, NULL, NULL, hInstance, NULL);

      if(hwnd == NULL) {
        MessageBox(NULL, "Window Creation Failed!", "Error!", MB_ICONEXCLAMATION | MB_OK);
        return 0;
      }

      ShowWindow(hwnd, nCmdShow);
      UpdateWindow(hwnd);

      while(GetMessage(&Msg, NULL, 0, 0) > 0) {
        TranslateMessage(&Msg);
        DispatchMessage(&Msg);
      }
      return Msg.wParam;
    }
