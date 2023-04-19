int		ft_atoi(char *str)
{
	int		count;
	int		negative;
	int		number;

	count = 0;
	negative = 0;
	number = 0;
	//verifica a ocorrencia de elem especiais
	while ((str[count] > 8 && str[count] < 14) || (str[count] == 32))
		count++;
	//verifica a ocorrencia de +-(usado em teste logico)
	while ((str[count] != '\0') && (str[count] == '+' || str[count] == '-'))
	{
		if (str[count] == '-')
			negative++;
		count++;
	}
	//verifica se esta dentro da escala dos numer
	while ((str[count] != '\0') && (str[count] >= 48 && str[count] <= 57))
	{
		//subtrai 48(0) p/ buscar a distancia p/ o 0
		//no prox ciclo o numero passado vai aumentar uma dezena
		number = number * 10 + str[count] - 48;
		count++;
	}
	//se a quant de +- for par, o numero e positivo
	if (negative % 2 != 0)
		return (number * -1);
	return (number);
}