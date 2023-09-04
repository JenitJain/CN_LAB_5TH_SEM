 #include <stdio.h>

struct student {
  int roll_number;
  char name[50];
  char gender;
  int mobile_number;
  int phy_mark;
  int chem_mark;
  int math_mark;
};

int main() {
  int n;
  printf("Enter the number of students: ");
  scanf("%d", &n);

  struct student students[n];

  for (int i = 0; i < n; i++) {
    printf("Enter the details of student %d:\n", i + 1);
    printf("Roll number: ");
    scanf("%d", &students[i].roll_number);
    printf("Name: ");
    scanf("%s", students[i].name);
    printf("Gender (M/F): ");
    scanf(" %c", &students[i].gender);
    printf("Mobile number: ");
    scanf("%d", &students[i].mobile_number);
    printf("Phy mark: ");
    scanf("%d", &students[i].phy_mark);
    printf("Chem mark: ");
    scanf("%d", &students[i].chem_mark);
    printf("Math mark: ");
    scanf("%d", &students[i].math_mark);
  }

  printf("\nStudent list:\n");
  printf("SL.No | Roll number | Name | Gender | Mobile number | Phy mark | Chem mark | Math mark\n");
  for (int i = 0; i < n; i++) {
    printf("%-3d | %-8d | %-10s | %-3c | %-10d | %-8d | %-8d | %-8d\n",
           i + 1, students[i].roll_number, students[i].name, students[i].gender,
           students[i].mobile_number, students[i].phy_mark, students[i].chem_mark,
           students[i].math_mark);
  }

  return 0;
}

