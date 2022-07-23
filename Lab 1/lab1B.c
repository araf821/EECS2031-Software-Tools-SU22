main()
{
	int m, d, y;
	printf("Enter month, day and year separated by spaces: ");
	
	scanf("%d %d %d", &m, &d, &y);
	
	printf("The input '%d %d %d' is reformatted as %d/%d/%d and %d-%d-%d\n", m, d, y, y, m, d, y, m, d);
}
