#include "pch.h"


matrix_struct *get_matrix_struct(char matrix[]) {
	matrix_struct *m = malloc(sizeof(matrix_struct));
	m->rows = 0;
	m->cols = 0;
	FILE* myfile = fopen(matrix, "r");

	if (myfile == NULL) {
		printf("Error: The file you entered could not be found.\n");
		exit(EXIT_FAILURE);
	}


	//get rows, cols

	int ch = 0;
	do {
		ch = fgetc(myfile);

		if (m->rows == 0 & ch == "\t") //count cols at first line 
			m->cols++;
		if (ch == '\n') {
			m->rows++;

		}
	} while (ch != EOF);

	m->cols++;
	m->mat_data = calloc(m->rows, sizeof(double*));
	int i;
	for (i = 0; i < m->rows; i++) {
		m->mat_data[i] = calloc(m->cols, sizeof(double));
	}
	rewind(myfile);
	int x, y;

}