#include <iostream>
#include <stack>
#include <string>

class PengolahKata {
private:
    std::stack<std::string> tumpukanUndo;
    std::stack<std::string> tumpukanRedo;
    std::string teksSaatIni;

public:
    void ketik(const std::string& teks) {
        tumpukanUndo.push(teksSaatIni);
        while (!tumpukanRedo.empty()) {
            tumpukanRedo.pop();
        }
        teksSaatIni += teks;
    }

    void undo() {
        if (!tumpukanUndo.empty()) {
            tumpukanRedo.push(teksSaatIni);
            teksSaatIni = tumpukanUndo.top();
            tumpukanUndo.pop();
        } else {
            std::cout << "Tidak ada teks yang bisa di-undo\n";
        }
    }

    void redo() {
        if (!tumpukanRedo.empty()) {
            tumpukanUndo.push(teksSaatIni);
            teksSaatIni = tumpukanRedo.top();
            tumpukanRedo.pop();
        } else {
            std::cout << "Tidak ada teks yang bisa di-redo\n";
        }
    }

    bool isEmptyUndo() const {
        return tumpukanUndo.empty();
    }

    bool isEmptyRedo() const {
        return tumpukanRedo.empty();
    }

    void tampilkan() const {
        std::cout << "Teks saat ini: " << teksSaatIni << "\n";
    }
};

    

int main() {
    PengolahKata editor;
    std::string perintah, teks;

    while (true) {
        std::cout << "\n________________________________\n";
        editor.tampilkan();
        std::cout << "________________________________\n";
        std::cout << "\n";
        std::cout << "Masukkan perintah sesuai nama:\n";
        std::cout << "1. ketik\n";
        std::cout << "2. undo\n";
        std::cout << "3. redo\n";
        std::cout << "4. is empty undo\n";
        std::cout << "5. is empty redo\n";
        std::cout << "6. keluar\n";
        std::cout << "Perintah Kamu: ";
        std::cin >> perintah;
        std::cout << "\n";


        if (perintah == "ketik") {
            std::cout << "Masukkan teks: ";
            std::cin.ignore(); 
            std::getline(std::cin, teks);
            editor.ketik(teks);
            std::cout << "\033[2J\033[1;1H" ;
        } else if (perintah == "undo") {
            editor.undo();
            std::cout << "\033[2J\033[1;1H" ;
        } else if (perintah == "redo") {
            editor.redo();
            std::cout << "\033[2J\033[1;1H" ;
        } else if (perintah == "is empty undo") {
            if (editor.isEmptyUndo()) {
                std::cout << "Tumpukan undo kosong.\n";
            } else {
                std::cout << "Tumpukan undo tidak kosong.\n";
            }
            std::cout << "\033[2J\033[1;1H" ;
        } else if (perintah == "is empty redo") {
            if (editor.isEmptyRedo()) {
                std::cout << "Tumpukan redo kosong.\n";
            } else {
                std::cout << "Tumpukan redo tidak kosong.\n";
            }
            std::cout << "\033[2J\033[1;1H" ;
        } else if (perintah == "keluar") {
            break;
        } else {
            std::cout << "Perintah tidak sesuai.\n";
        }
    }
           
    return 0;
}
