import pygame.font
import pygame
import sys

p1_colour = (255, 0, 127) # pink
p2_colour = (0,238,238) # light cyan
grid_colour = (32, 32, 32) # grey

class Piece:
	"""A class that will display the pieces"""

	def __init__(self, filler):
		"""Init piece"""
		self.screen = filler.screen
		self.screen_rect = self.screen.get_rect()
		self.settings = filler.settings
		self.player = filler.player

	def draw_piece(self):
		"""Draws the piece underneath the respective player"""
		g_size = 200
		str_line = []
		line = self.settings.line.rstrip(':').split(' ')
		p_height = int(line[1])
		p_width = int(line[2])
		if p_height < p_width:
			p_scale = int(p_width)
		else:
			p_scale = int(p_height)
		p_size = g_size / p_scale

		p1_rect = pygame.Rect(0, 0, g_size, g_size)
		p2_rect = pygame.Rect(0, 0, g_size, g_size)
		# empty grid positions
		p1_rect.centerx = self.player.player1_rect.centerx
		p1_rect.top = self.player.player1_rect.bottom + 40
		p2_rect.centerx = self.player.player2_rect.centerx
		p2_rect.top = self.player.player2_rect.bottom + 40

		clear_piece = pygame.Surface((g_size, g_size))
		clear_piece.fill(self.settings.bg_colour)

		p1_piece = pygame.Surface((p_size - 1, p_size - 1))
		p1_piece.fill(p1_colour)
		p2_piece = pygame.Surface((p_size - 1, p_size - 1))
		p2_piece.fill(p2_colour)
		empty = pygame.Surface((p_size - 1, p_size - 1))
		empty.fill(grid_colour)

		i = 0
		y = 0
		x = 0
		for i in range(p_height):
			str_line.append(sys.stdin.readline().rstrip('\n'))
		self.settings.line = sys.stdin.readline().rstrip('\n')
		y_grid = p1_rect.y
		x_grid = p1_rect.x
		rect_x = p1_rect.x
		piece = p1_piece
		if ' (O):' in self.settings.line :
			self.screen.blit(clear_piece, p1_rect)
		elif ' (X):' in self.settings.line :
			y_grid = p2_rect.y
			x_grid = p2_rect.x
			rect_x = p2_rect.x
			piece = p2_piece
			self.screen.blit(clear_piece, p2_rect)
		while (y < int(p_height)):
			x = 0
			while (x < int(p_width)):
				if (str_line[y][x] == '*'):
					self.screen.blit(piece, (x_grid, y_grid))
				if (str_line[y][x] == '.'):
					self.screen.blit(empty, (x_grid, y_grid))
				x += 1
				x_grid += p_size
			x_grid = rect_x
			y_grid += p_size
			y += 1
