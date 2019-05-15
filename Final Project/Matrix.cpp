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


	for (x = 0; x < m->rows; x++) {
		for (y = 0; y < m->cols; y++) { //parsing matrix for filling it with data
			if (!fscanf(myfile, "%lf", &m->mat_data[x][y])) {
				break;
			}

		}
	}
	fclose(myfile);
	return m;

	void print_matrix(matrix_struct *matrix_to_print) {
		int i, j;
		for (i = 0; i < matrix_to_print->rows; i++) {
			for (j = 0; j < matrix_to_print->cols; j++) {

				printf("%lf\t", matrix_to_print->mat_data[i][j];

			}
			printf("\n");
		}
	}

	void free_matrix(matrix_struct *matrix_to_free) {
		int i, j;
		for (i = 0; i < matrix_to_free->rows; i++) {
			for (j = 0; j < matrix_to_free->cols; j++) {
				free(matrix_to_free->mat_data[i]);
			}
			free(matrix_to_free->mat_data);
			free(matrix_to_free);
		}
	}
}