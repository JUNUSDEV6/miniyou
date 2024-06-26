/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lexer_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegros <clegros@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 15:56:50 by clegros           #+#    #+#             */
/*   Updated: 2024/05/14 16:02:05 by clegros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	free_list(t_lexer *list)
{
	t_lexer	*temp;

	while (list != NULL)
	{
		temp = list;
		list = list->next;
		free(temp->token);
		free(temp);
	}
}

void	print_list(t_lexer *list)
{
	int	i;

	i = 1;
	while (list != NULL)
	{
		printf("lexer %d : %s\n", i++, list->token);
		list = list->next;
	}
}

void	add_token(t_lexer **list, char *token)
{
	t_lexer	*new_token;
	t_lexer	*current;

	new_token = (t_lexer *)malloc(sizeof(t_lexer));
	if (new_token == NULL)
	{
		fprintf(stderr, "Erreur d'allocation mémoire\n");
		exit(EXIT_FAILURE);
	}
	new_token->token = strdup(token);
	new_token->next = NULL;
	if (*list == NULL)
		*list = new_token;
	else
	{
		current = *list;
		while (current->next != NULL)
			current = current->next;
		current->next = new_token;
	}
}

void	add_current_token(t_lexer **list, char **token_start, char *current)
{
	*current = '\0';
	add_token(list, *token_start);
	*token_start = current + 1;
}
