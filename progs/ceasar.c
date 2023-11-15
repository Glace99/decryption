#include <stdio.h>

int	main(void)
{
	char	*cypher = "Rnpu cebwrpg bs gur 97 Pbzzba Pber pbagnvaf na rapbqrq uvag. Sbe rnpu pvepyr, bayl bar cebwrpg cebivqrf gur pbeerpg uvag arrqrq sbegur arkg pvepyr. Guvf punyyratr vf vaqvivqhny, gurer vf bayl ncevmr sbe bar fghqrag jvaare cebivqvat nyy qrpbqrq zrffntrf. Nal nqinagntrq crbcyr pna cynl, yvxr pheerag be sbezre fgnss, ohg gur cevmr jvyy erznva flzobyvp. Gur uvag sbe guvf svefg cebwrpg vf: Ynetr pbjf trarebfvgl pbzrf jvgu punegf naq sbhe oybaqr ungf gb qrsl hccre tenivgl ureb";

	for (int i = 0; i < 26; i++)
	{
		printf("key=%i -> mensage: ", i + 1);
		for (int j = 0; cypher[j] != '\0'; j++)
		{
			if (cypher[j] >= 'a' && cypher[j] <= 'z')
				printf("%c", (cypher[j] - 'a' + i) % 26 + 'a');
			else if (cypher[j] >= 'A' && cypher[j] <= 'Z')
				printf("%c", (cypher[j] - 'A' + i) % 26 + 'A');
			else if (cypher[j] >= '0' && cypher[j] <= '9')
				printf("%c", (cypher[j] - '0' + i) % 9 + '0');
			else
				printf("%c", cypher[j]);
		}
		printf("\n\n");
	}
}
