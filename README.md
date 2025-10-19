# Knight's tour som Greedy

Dette C-program er lavet i forbindelse med kursus: **62712- Basic C-programmeing**, der implementerer en **greedy** løsning *Knights Tour* problemet. 

Med start fra position **(0,0)** på boardet, vælger springeren altid det **første lovlige træk** i en fast rækkefølge. Turen stopper, når der ikke er flere mulige træk for springeren at udføre.
For alle startfelter bliver antallet af besøgte felter** udskrevet i en tabel.

## Filer
- `knights_tour.h` – **konstanter og typer**, samt **deklarering** af funktioner.
- `knights_tour.c` – **implementering** af funktioner
- `main.c` – **kalder den samlede kørsel**, samt **udskrivning** af antallet af besøgte felter fra hver start position

Boardets **standard størrelse** er sat til `8` og ændres under `knights_tour.h` for konstanten `SIZE`.

### Funktioner
- `bool move_is_possible(size_t move_id, size_t x, size_t y, board_t visited);`  
  – **Tjekker** trækket for springeren er muligt og om cellen på boardet allerede er **besøgt**.
- `unsigned int tour_greedy(size_t start_x, size_t start_y);`  
  – **Kører** en hel tour indtil der ikke findes flere mulige træk for springeren at tage og **udskriver** antallet af træk.
- `void greedy_tour_from_each_square(void);`  
  – **Kører** hele touren for det antal af felter der er blevet valgt og **udskriver** antallet.


## Kørsel eksempel: Udskrift for `SIZE=8` board

```
Greedy:
36 37 43 49 36 35 48 42
54 43 35 36 42 48 35 34
36 29 54 42 34 35 41 47
42 28 35 28 54 41 33 34
45 35 41 27 26 27 46 40
40  8 44 44 40 26 33 32
10 54 46 54 55 31 39 54
42 37 35 55 36 32 35 32
```
