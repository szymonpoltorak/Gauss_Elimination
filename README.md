# Eliminacja Gausa

Program robiony w ramach zajęć laboratyjnych z języków i metod programowania w piewrszym semestrze studiów na kierunku informatyka stosowana. Celem zadania było stworzenie programu czytającego z pliku macierze i dokonywanie eliminacji gaussa w celu znalezienia wyniku. Program ma dwa tryby działania, z czego drugi uruchamiamy poprzez dodanie jako czwarty argument wywołania flagi `-USE_MAX`.

# Kompilacja programu

Do kompilacji programu używamy komendy `make`. Komenda `make clean` usuwa wszelkie pliki i foldery robocze oraz pliki wykonywalne.

# Składnia programu

Program wymaga przestrzegania kolejności argumentów wywołania.\
`./matrix [plik] [macierz wynikowa] [opcjonalna flaga]`

# Testy

Program ma wbudowane moduły do testowania. Kompilacja programu testowego odbywa się poprzez użycie komendy:\
`make test`\
Następnym krokiem jest zwykłe uruchomienie programu testującego poprzez komendę:\
`./test`

