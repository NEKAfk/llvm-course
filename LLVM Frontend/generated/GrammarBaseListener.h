
// Generated from Grammar.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"
#include "GrammarListener.h"


/**
 * This class provides an empty implementation of GrammarListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  GrammarBaseListener : public GrammarListener {
public:

  virtual void enterProgram(GrammarParser::ProgramContext * /*ctx*/) override { }
  virtual void exitProgram(GrammarParser::ProgramContext * /*ctx*/) override { }

  virtual void enterFunDecl(GrammarParser::FunDeclContext * /*ctx*/) override { }
  virtual void exitFunDecl(GrammarParser::FunDeclContext * /*ctx*/) override { }

  virtual void enterLine(GrammarParser::LineContext * /*ctx*/) override { }
  virtual void exitLine(GrammarParser::LineContext * /*ctx*/) override { }

  virtual void enterForExpr(GrammarParser::ForExprContext * /*ctx*/) override { }
  virtual void exitForExpr(GrammarParser::ForExprContext * /*ctx*/) override { }

  virtual void enterIfExpr(GrammarParser::IfExprContext * /*ctx*/) override { }
  virtual void exitIfExpr(GrammarParser::IfExprContext * /*ctx*/) override { }

  virtual void enterWhileExpr(GrammarParser::WhileExprContext * /*ctx*/) override { }
  virtual void exitWhileExpr(GrammarParser::WhileExprContext * /*ctx*/) override { }

  virtual void enterExpr(GrammarParser::ExprContext * /*ctx*/) override { }
  virtual void exitExpr(GrammarParser::ExprContext * /*ctx*/) override { }

  virtual void enterFunParams(GrammarParser::FunParamsContext * /*ctx*/) override { }
  virtual void exitFunParams(GrammarParser::FunParamsContext * /*ctx*/) override { }

  virtual void enterAssign(GrammarParser::AssignContext * /*ctx*/) override { }
  virtual void exitAssign(GrammarParser::AssignContext * /*ctx*/) override { }

  virtual void enterCreate(GrammarParser::CreateContext * /*ctx*/) override { }
  virtual void exitCreate(GrammarParser::CreateContext * /*ctx*/) override { }

  virtual void enterVarDecl(GrammarParser::VarDeclContext * /*ctx*/) override { }
  virtual void exitVarDecl(GrammarParser::VarDeclContext * /*ctx*/) override { }

  virtual void enterArrDecl(GrammarParser::ArrDeclContext * /*ctx*/) override { }
  virtual void exitArrDecl(GrammarParser::ArrDeclContext * /*ctx*/) override { }

  virtual void enterReturnExpr(GrammarParser::ReturnExprContext * /*ctx*/) override { }
  virtual void exitReturnExpr(GrammarParser::ReturnExprContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

