int	shell_is_interactive()
{
	
	int	shell;

	shell = STD_FILENO;
	if (isatty(shell))
		return (SUCCES);
	return (FAILURE);
}

