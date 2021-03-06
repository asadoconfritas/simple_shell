	if (!arguments[0])
	{
		return (0);
	}
	_strcat(str_cocat, arguments[0]);
	if (_strcmp(arguments[0], "exit") == 0)
	{
		free(arguments);
		free(line);
		exit(EXIT_SUCCESS);
	}
	else if (_strcmp(arguments[0], "env") == 0)
	{
		for (i = 0; environ[i] != NULL; i++)
			printf("%s\n", environ[i]);
	}
	else if (access(arguments[0], F_OK) != -1)
	{
		child_process = fork();
		if (child_process == 0)
			execve(str_cocat, arguments, environ);
		wait(&status);
	}
	else if (flag == 1)
		printf("%s: %i: %s: not found\n", argv[0], count, arguments[]);
	else
		printf("%s: %i: %s: not found\n", argv[0], count, arguments[]);
	return (0);
}
