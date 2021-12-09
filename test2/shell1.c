/**
 * main - main func
 * @argc: n of args
 * @argv: array of args
 * Return: end program
 **/
int main(int argc, char **argv)
{
	char *cmd;
	while (1)
	{
		print_prompt1();
		cmd = read_cmd();
		if(!cmd)
		{
		exit(EXIT_SUCCESS);
		}
		if(cmd[0] == '\0' || _strcmp(cmd, "\n") == 0)
		{
		free(cmd);
		continue;
		}
		if(_strcmp(cmd, "exit\n") == 0)
		{
		free(cmd);
		break;
		}
	}
	exit(EXIT_SUCCESS);
}
