#include<stdio.h>

int main(){
	FILE *fp;
	fp = fopen("/nfs/file.h", "w");
	int l;
	scanf("%d", &l);


	fprintf(fp, "#include<stdio.h>\n");
	fprintf(fp, "int l = %d;\n", l);
	fprintf(fp, "int arr[%d][%d] = {", l, l);

	for(int i = 1; i <= l*l; i++){
		fprintf(fp, "%d", 1);
		if(i == l*l)
			continue;
		else
			fprintf(fp, ", ");
	}

	fprintf(fp, "};\n");

	fprintf(fp, "int ans[%d][%d] = {", l, l);

	for(int i = 1; i <= l*l; i++){
		fprintf(fp, "%d", 0);
		if(i == l*l)
			continue;
		else
			fprintf(fp, ", ");
	}

	fprintf(fp, "};\n");

	
	fclose(fp);
	return 0;
}