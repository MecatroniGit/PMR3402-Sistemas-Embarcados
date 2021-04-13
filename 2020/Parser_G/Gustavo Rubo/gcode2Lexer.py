# Generated from gcode2.g by ANTLR 4.7.2
from antlr4 import *
from io import StringIO
from typing.io import TextIO
import sys


def serializedATN():
    with StringIO() as buf:
        buf.write("\3\u608b\ua72a\u8133\ub9ed\u417c\u3be7\u7786\u5964\2\17")
        buf.write("I\b\1\4\2\t\2\4\3\t\3\4\4\t\4\4\5\t\5\4\6\t\6\4\7\t\7")
        buf.write("\4\b\t\b\4\t\t\t\4\n\t\n\4\13\t\13\4\f\t\f\4\r\t\r\4\16")
        buf.write("\t\16\3\2\3\2\3\3\3\3\3\3\3\3\3\4\3\4\3\4\3\4\3\5\3\5")
        buf.write("\3\5\3\5\3\6\3\6\3\6\3\6\3\7\3\7\3\7\3\7\3\b\3\b\3\t\3")
        buf.write("\t\3\n\3\n\3\13\3\13\3\f\3\f\3\r\6\r?\n\r\r\r\16\r@\3")
        buf.write("\16\6\16D\n\16\r\16\16\16E\3\16\3\16\2\2\17\3\3\5\4\7")
        buf.write("\5\t\6\13\7\r\b\17\t\21\n\23\13\25\f\27\r\31\16\33\17")
        buf.write("\3\2\4\3\2c|\4\2\13\13\"\"\2J\2\3\3\2\2\2\2\5\3\2\2\2")
        buf.write("\2\7\3\2\2\2\2\t\3\2\2\2\2\13\3\2\2\2\2\r\3\2\2\2\2\17")
        buf.write("\3\2\2\2\2\21\3\2\2\2\2\23\3\2\2\2\2\25\3\2\2\2\2\27\3")
        buf.write("\2\2\2\2\31\3\2\2\2\2\33\3\2\2\2\3\35\3\2\2\2\5\37\3\2")
        buf.write("\2\2\7#\3\2\2\2\t\'\3\2\2\2\13+\3\2\2\2\r/\3\2\2\2\17")
        buf.write("\63\3\2\2\2\21\65\3\2\2\2\23\67\3\2\2\2\259\3\2\2\2\27")
        buf.write(";\3\2\2\2\31>\3\2\2\2\33C\3\2\2\2\35\36\7P\2\2\36\4\3")
        buf.write("\2\2\2\37 \7O\2\2 !\7\65\2\2!\"\7\62\2\2\"\6\3\2\2\2#")
        buf.write("$\7O\2\2$%\7\62\2\2%&\7\64\2\2&\b\3\2\2\2\'(\7O\2\2()")
        buf.write("\7\62\2\2)*\7\63\2\2*\n\3\2\2\2+,\7I\2\2,-\7\62\2\2-.")
        buf.write("\7\63\2\2.\f\3\2\2\2/\60\7I\2\2\60\61\7\62\2\2\61\62\7")
        buf.write("\62\2\2\62\16\3\2\2\2\63\64\7Z\2\2\64\20\3\2\2\2\65\66")
        buf.write("\7[\2\2\66\22\3\2\2\2\678\7\17\2\28\24\3\2\2\29:\7\f\2")
        buf.write("\2:\26\3\2\2\2;<\4\62;\2<\30\3\2\2\2=?\t\2\2\2>=\3\2\2")
        buf.write("\2?@\3\2\2\2@>\3\2\2\2@A\3\2\2\2A\32\3\2\2\2BD\t\3\2\2")
        buf.write("CB\3\2\2\2DE\3\2\2\2EC\3\2\2\2EF\3\2\2\2FG\3\2\2\2GH\b")
        buf.write("\16\2\2H\34\3\2\2\2\5\2@E\3\b\2\2")
        return buf.getvalue()


class gcode2Lexer(Lexer):

    atn = ATNDeserializer().deserialize(serializedATN())

    decisionsToDFA = [ DFA(ds, i) for i, ds in enumerate(atn.decisionToState) ]

    T__0 = 1
    T__1 = 2
    T__2 = 3
    T__3 = 4
    T__4 = 5
    T__5 = 6
    T__6 = 7
    T__7 = 8
    T__8 = 9
    T__9 = 10
    INT = 11
    ID = 12
    WS = 13

    channelNames = [ u"DEFAULT_TOKEN_CHANNEL", u"HIDDEN" ]

    modeNames = [ "DEFAULT_MODE" ]

    literalNames = [ "<INVALID>",
            "'N'", "'M30'", "'M02'", "'M01'", "'G01'", "'G00'", "'X'", "'Y'", 
            "'\r'", "'\n'" ]

    symbolicNames = [ "<INVALID>",
            "INT", "ID", "WS" ]

    ruleNames = [ "T__0", "T__1", "T__2", "T__3", "T__4", "T__5", "T__6", 
                  "T__7", "T__8", "T__9", "INT", "ID", "WS" ]

    grammarFileName = "gcode2.g"

    def __init__(self, input=None, output:TextIO = sys.stdout):
        super().__init__(input, output)
        self.checkVersion("4.7.2")
        self._interp = LexerATNSimulator(self, self.atn, self.decisionsToDFA, PredictionContextCache())
        self._actions = None
        self._predicates = None


