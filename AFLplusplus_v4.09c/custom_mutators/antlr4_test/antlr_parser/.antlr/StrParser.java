// Generated from /home/xyf/antlr_wat/AFLplusplus_v4.09c/custom_mutators/antlr4_test/antlr_parser/StrParser.g4 by ANTLR 4.13.1
import org.antlr.v4.runtime.atn.*;
import org.antlr.v4.runtime.dfa.DFA;
import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.misc.*;
import org.antlr.v4.runtime.tree.*;
import java.util.List;
import java.util.Iterator;
import java.util.ArrayList;

@SuppressWarnings({"all", "warnings", "unchecked", "unused", "cast", "CheckReturnValue"})
public class StrParser extends Parser {
	static { RuntimeMetaData.checkVersion("4.13.1", RuntimeMetaData.VERSION); }

	protected static final DFA[] _decisionToDFA;
	protected static final PredictionContextCache _sharedContextCache =
		new PredictionContextCache();
	public static final int
		KEY=1, DIGIT=2, LETTER=3, LPAR=4, RPAR=5, LBRACE=6, RBRACE=7;
	public static final int
		RULE_left = 0, RULE_middle = 1, RULE_right = 2, RULE_module = 3;
	private static String[] makeRuleNames() {
		return new String[] {
			"left", "middle", "right", "module"
		};
	}
	public static final String[] ruleNames = makeRuleNames();

	private static String[] makeLiteralNames() {
		return new String[] {
			null, "'visit'", null, null, "'('", "')'", "'{'", "'}'"
		};
	}
	private static final String[] _LITERAL_NAMES = makeLiteralNames();
	private static String[] makeSymbolicNames() {
		return new String[] {
			null, "KEY", "DIGIT", "LETTER", "LPAR", "RPAR", "LBRACE", "RBRACE"
		};
	}
	private static final String[] _SYMBOLIC_NAMES = makeSymbolicNames();
	public static final Vocabulary VOCABULARY = new VocabularyImpl(_LITERAL_NAMES, _SYMBOLIC_NAMES);

	/**
	 * @deprecated Use {@link #VOCABULARY} instead.
	 */
	@Deprecated
	public static final String[] tokenNames;
	static {
		tokenNames = new String[_SYMBOLIC_NAMES.length];
		for (int i = 0; i < tokenNames.length; i++) {
			tokenNames[i] = VOCABULARY.getLiteralName(i);
			if (tokenNames[i] == null) {
				tokenNames[i] = VOCABULARY.getSymbolicName(i);
			}

			if (tokenNames[i] == null) {
				tokenNames[i] = "<INVALID>";
			}
		}
	}

	@Override
	@Deprecated
	public String[] getTokenNames() {
		return tokenNames;
	}

	@Override

	public Vocabulary getVocabulary() {
		return VOCABULARY;
	}

	@Override
	public String getGrammarFileName() { return "StrParser.g4"; }

	@Override
	public String[] getRuleNames() { return ruleNames; }

	@Override
	public String getSerializedATN() { return _serializedATN; }

	@Override
	public ATN getATN() { return _ATN; }

	public StrParser(TokenStream input) {
		super(input);
		_interp = new ParserATNSimulator(this,_ATN,_decisionToDFA,_sharedContextCache);
	}

	@SuppressWarnings("CheckReturnValue")
	public static class LeftContext extends ParserRuleContext {
		public TerminalNode LPAR() { return getToken(StrParser.LPAR, 0); }
		public TerminalNode RPAR() { return getToken(StrParser.RPAR, 0); }
		public List<TerminalNode> DIGIT() { return getTokens(StrParser.DIGIT); }
		public TerminalNode DIGIT(int i) {
			return getToken(StrParser.DIGIT, i);
		}
		public LeftContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_left; }
	}

	public final LeftContext left() throws RecognitionException {
		LeftContext _localctx = new LeftContext(_ctx, getState());
		enterRule(_localctx, 0, RULE_left);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(8);
			match(LPAR);
			setState(10); 
			_errHandler.sync(this);
			_la = _input.LA(1);
			do {
				{
				{
				setState(9);
				match(DIGIT);
				}
				}
				setState(12); 
				_errHandler.sync(this);
				_la = _input.LA(1);
			} while ( _la==DIGIT );
			setState(14);
			match(RPAR);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class MiddleContext extends ParserRuleContext {
		public TerminalNode KEY() { return getToken(StrParser.KEY, 0); }
		public MiddleContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_middle; }
	}

	public final MiddleContext middle() throws RecognitionException {
		MiddleContext _localctx = new MiddleContext(_ctx, getState());
		enterRule(_localctx, 2, RULE_middle);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(16);
			match(KEY);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class RightContext extends ParserRuleContext {
		public TerminalNode LBRACE() { return getToken(StrParser.LBRACE, 0); }
		public TerminalNode RBRACE() { return getToken(StrParser.RBRACE, 0); }
		public List<TerminalNode> LETTER() { return getTokens(StrParser.LETTER); }
		public TerminalNode LETTER(int i) {
			return getToken(StrParser.LETTER, i);
		}
		public RightContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_right; }
	}

	public final RightContext right() throws RecognitionException {
		RightContext _localctx = new RightContext(_ctx, getState());
		enterRule(_localctx, 4, RULE_right);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(18);
			match(LBRACE);
			setState(20); 
			_errHandler.sync(this);
			_la = _input.LA(1);
			do {
				{
				{
				setState(19);
				match(LETTER);
				}
				}
				setState(22); 
				_errHandler.sync(this);
				_la = _input.LA(1);
			} while ( _la==LETTER );
			setState(24);
			match(RBRACE);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class ModuleContext extends ParserRuleContext {
		public LeftContext left() {
			return getRuleContext(LeftContext.class,0);
		}
		public MiddleContext middle() {
			return getRuleContext(MiddleContext.class,0);
		}
		public RightContext right() {
			return getRuleContext(RightContext.class,0);
		}
		public TerminalNode EOF() { return getToken(StrParser.EOF, 0); }
		public ModuleContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_module; }
	}

	public final ModuleContext module() throws RecognitionException {
		ModuleContext _localctx = new ModuleContext(_ctx, getState());
		enterRule(_localctx, 6, RULE_module);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(26);
			left();
			setState(27);
			middle();
			setState(28);
			right();
			setState(29);
			match(EOF);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static final String _serializedATN =
		"\u0004\u0001\u0007 \u0002\u0000\u0007\u0000\u0002\u0001\u0007\u0001\u0002"+
		"\u0002\u0007\u0002\u0002\u0003\u0007\u0003\u0001\u0000\u0001\u0000\u0004"+
		"\u0000\u000b\b\u0000\u000b\u0000\f\u0000\f\u0001\u0000\u0001\u0000\u0001"+
		"\u0001\u0001\u0001\u0001\u0002\u0001\u0002\u0004\u0002\u0015\b\u0002\u000b"+
		"\u0002\f\u0002\u0016\u0001\u0002\u0001\u0002\u0001\u0003\u0001\u0003\u0001"+
		"\u0003\u0001\u0003\u0001\u0003\u0001\u0003\u0000\u0000\u0004\u0000\u0002"+
		"\u0004\u0006\u0000\u0000\u001d\u0000\b\u0001\u0000\u0000\u0000\u0002\u0010"+
		"\u0001\u0000\u0000\u0000\u0004\u0012\u0001\u0000\u0000\u0000\u0006\u001a"+
		"\u0001\u0000\u0000\u0000\b\n\u0005\u0004\u0000\u0000\t\u000b\u0005\u0002"+
		"\u0000\u0000\n\t\u0001\u0000\u0000\u0000\u000b\f\u0001\u0000\u0000\u0000"+
		"\f\n\u0001\u0000\u0000\u0000\f\r\u0001\u0000\u0000\u0000\r\u000e\u0001"+
		"\u0000\u0000\u0000\u000e\u000f\u0005\u0005\u0000\u0000\u000f\u0001\u0001"+
		"\u0000\u0000\u0000\u0010\u0011\u0005\u0001\u0000\u0000\u0011\u0003\u0001"+
		"\u0000\u0000\u0000\u0012\u0014\u0005\u0006\u0000\u0000\u0013\u0015\u0005"+
		"\u0003\u0000\u0000\u0014\u0013\u0001\u0000\u0000\u0000\u0015\u0016\u0001"+
		"\u0000\u0000\u0000\u0016\u0014\u0001\u0000\u0000\u0000\u0016\u0017\u0001"+
		"\u0000\u0000\u0000\u0017\u0018\u0001\u0000\u0000\u0000\u0018\u0019\u0005"+
		"\u0007\u0000\u0000\u0019\u0005\u0001\u0000\u0000\u0000\u001a\u001b\u0003"+
		"\u0000\u0000\u0000\u001b\u001c\u0003\u0002\u0001\u0000\u001c\u001d\u0003"+
		"\u0004\u0002\u0000\u001d\u001e\u0005\u0000\u0000\u0001\u001e\u0007\u0001"+
		"\u0000\u0000\u0000\u0002\f\u0016";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}