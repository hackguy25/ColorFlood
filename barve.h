// To je header za uporabo različnih barv v bash ukazni vrstici.
// Obvezno mora biti v mapi poleg programa v času klica ukaza gcc
// #import "barve.h"
// Uporaba: printf(<barva>); - npr. printf(BLU);
// reset: printf(BREZ);

#define BLK "\033[0;30m"
#define RED "\033[0;31m"
#define GRN "\033[0;32m"
#define ORG "\033[0;33m"
#define BLU "\033[0;34m"
#define PRP "\033[0;35m"
#define CYN "\033[0;36m"
#define L_GRY "\033[0;37m"
#define D_GRY "\033[1;30m"
#define L_RED "\033[1;31m"
#define L_GRN "\033[1;32m"
#define YLW "\033[1;33m"
#define L_BLU "\033[1;34m"
#define L_PRP "\033[1;35m"
#define L_CYN "\033[1;36m"
#define WHT "\033[1;37m"

#define BREZ "\033[0m"	// odstrani barvo - povrne na sistemski default
#define CLEAR "\033c"	// počisti vsebino okna
#define OSEMDESET_ZA_TRIDESET "\e[8;30;80t"			// spremeni velikost na 80 * 30 znakov
#define OSEMDESET_ZA_STIRIINDVAJSET "\e[8;24;80t"	// spremeni velikost na privzeto velikost

#define NOVA "\n"		// nova vrstica
#define KVAD "\u25A0 "	// izpiše kvadratek: ■

// Priročna tabela z vsemi barvami, kličeš z printf("%s", barve[i]);

static char barve[16][8] = {BLK, RED, GRN, ORG, BLU, PRP, CYN, L_GRY, D_GRY, L_RED, L_GRN, YLW, L_BLU,
L_PRP, L_CYN, WHT};
