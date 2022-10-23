import pygame
import pygame.font
import sys

black = (0, 0, 0)
orange = (254, 184, 70)
navy = (0, 0, 25)
grey = (32, 32, 32)
peach = (248, 118, 154)

class Grid:
	"""A class that will display the playing grid"""

	def __init__(self, filler):
		"""Init grid"""

		self.screen = filler.screen
		self.screen_rect = self.screen.get_rect()
		self.settings = filler.settings

		self.width, self.height = 450, 450
		self.grid_colour = black
		self.p1_score = 0
		self.p2_score = 0

		self.rect = pygame.Rect(0, 0, self.width, self.height)
		self.rect.center = self.screen_rect.center
		self.rect.bottom = self.screen_rect.bottom - 50

	def draw_board(self):
		"""draw the grid"""
		y = 0
		x = 0
		p1_turn = 0
		p2_turn = 0
		y_grid = self.rect.y
		x_grid = self.rect.x
		str = sys.stdin.readline()
		while (y < int(self.settings.m_height)):
			str = sys.stdin.readline().rstrip('\n').split(' ')
			grid_str = str[-1]
			x = 0
			while (x < int(self.settings.m_width)):
				if grid_str[x] == '.':
					self.screen.blit(self.settings.empty, (x_grid, y_grid))
				if grid_str[x] == 'O':
					self.screen.blit(self.settings.p1_old_piece, (x_grid, y_grid))
				if grid_str[x] == 'X':
					self.screen.blit(self.settings.p2_old_piece, (x_grid, y_grid))
				if grid_str[x] == 'o':
					p1_turn = 1
					self.screen.blit(self.settings.p1_new_piece, (x_grid, y_grid))
				if grid_str[x] == 'x':
					p2_turn = 1
					self.screen.blit(self.settings.p2_new_piece, (x_grid, y_grid))
				x += 1
				x_grid += self.settings.grid_side + 1
			x_grid = self.rect.x
			y_grid += self.settings.grid_side + 1
			y += 1
		self.settings.line = grid_str
		if p1_turn == 1:
			self.settings.p1_score += 1
		elif p2_turn == 1:
			self.settings.p2_score += 1
