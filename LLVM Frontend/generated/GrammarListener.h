
// Generated from Grammar.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"
#include "GrammarParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by GrammarParser.
 */
class  GrammarListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterProgram(GrammarParser::ProgramContext *ctx) = 0;
  virtual void exitProgram(GrammarParser::ProgramContext *ctx) = 0;

  virtual void enterFunDecl(GrammarParser::FunDeclContext *ctx) = 0;
  virtual void exitFunDecl(GrammarParser::FunDeclContext *ctx) = 0;

  virtual void enterLine(GrammarParser::LineContext *ctx) = 0;
  virtual void exitLine(GrammarParser::LineContext *ctx) = 0;

  virtual void enterForExpr(GrammarParser::ForExprContext *ctx) = 0;
  virtual void exitForExpr(GrammarParser::ForExprContext *ctx) = 0;

  virtual void enterIfExpr(GrammarParser::IfExprContext *ctx) = 0;
  virtual void exitIfExpr(GrammarParser::IfExprContext *ctx) = 0;

  virtual void enterWhileExpr(GrammarParser::WhileExprContext *ctx) = 0;
  virtual void exitWhileExpr(GrammarParser::WhileExprContext *ctx) = 0;

  virtual void enterExpr(GrammarParser::ExprContext *ctx) = 0;
  virtual void exitExpr(GrammarParser::ExprContext *ctx) = 0;

  virtual void enterFunParams(GrammarParser::FunParamsContext *ctx) = 0;
  virtual void exitFunParams(GrammarParser::FunParamsContext *ctx) = 0;

  virtual void enterAssign(GrammarParser::AssignContext *ctx) = 0;
  virtual void exitAssign(GrammarParser::AssignContext *ctx) = 0;

  virtual void enterCreate(GrammarParser::CreateContext *ctx) = 0;
  virtual void exitCreate(GrammarParser::CreateContext *ctx) = 0;

  virtual void enterVarDecl(GrammarParser::VarDeclContext *ctx) = 0;
  virtual void exitVarDecl(GrammarParser::VarDeclContext *ctx) = 0;

  virtual void enterArrDecl(GrammarParser::ArrDeclContext *ctx) = 0;
  virtual void exitArrDecl(GrammarParser::ArrDeclContext *ctx) = 0;

  virtual void enterReturnExpr(GrammarParser::ReturnExprContext *ctx) = 0;
  virtual void exitReturnExpr(GrammarParser::ReturnExprContext *ctx) = 0;


};

