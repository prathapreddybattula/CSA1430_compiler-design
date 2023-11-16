#include <stdio.h>
#include <string.h>

typedef struct {
  char lhs;
  char rhs[100];
} ProductionRule;

int canParse(ProductionRule *rules, int numRules, char *str) {
  
  if (strlen(str) == 0) {
    return 1;
  }

  for (int i = 0; i < numRules; i++) {
    
    if (rules[i].lhs == str[0]) {
      if (canParse(rules, numRules, str + 1)) {
        return 1;
      }
    }
  }

  return 0;
}


int isAmbiguous(ProductionRule *rules, int numRules) {
  
  for (int i = 0; i < numRules; i++) {
    for (int j = i + 1; j < numRules; j++) {
      char str[100];
      strcpy(str, rules[i].rhs);
      strcat(str, rules[j].rhs);

      if (canParse(rules, numRules, str)) {
        return 1;
      }
    }
  }

  return 0;
}

int main() {

  int numRules;
  printf("Enter the number of production rules in the grammar: ");
  scanf("%d", &numRules);

  ProductionRule rules[numRules];

  for (int i = 0; i < numRules; i++) {
    printf("Enter production rule %d: ", i + 1);
    scanf("%c -> %s", &rules[i].lhs, rules[i].rhs);
  }

  if (isAmbiguous(rules, numRules)) {
    printf("The grammar is ambiguous.\n");
  } else {
    printf("The grammar is unambiguous.\n");
  }

  return 0;
}
