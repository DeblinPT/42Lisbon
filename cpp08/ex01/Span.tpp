/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.tpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adimas-d <adimas-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 13:17:39 by adimas-d          #+#    #+#             */
/*   Updated: 2025/05/07 17:49:06 by adimas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template<typename it>
void	Span::addNumbers(it begin, it end) {
	if (_data.size() + std::distance(begin, end) > _size)
		throw MaxCap();
	_data.insert(_data.end(), begin, end);
}