import sys
from antlr4 import *
from gcode2Lexer import gcode2Lexer
from gcode2Parser import gcode2Parser
from gcode2Listener import gcode2Listener

class gcode2Listener(ParseTreeListener):

    def exitCoord(self, ctx):
        print(ctx.getText(), end = " ")

    def exitStatement(self, ctx):
        print("")

def main(argv):
    input = FileStream(argv[1])
    lexer = gcode2Lexer(input)
    stream = CommonTokenStream(lexer)
    parser = gcode2Parser(stream)
    tree = parser.prg()
    
    listener = gcode2Listener()
    walker = ParseTreeWalker()
    walker.walk(listener, tree)

if __name__ == '__main__':
    main(sys.argv)