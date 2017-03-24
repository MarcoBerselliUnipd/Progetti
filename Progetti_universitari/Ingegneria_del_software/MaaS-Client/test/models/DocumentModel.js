import React from 'react';
import
{
  shallow
}
from 'enzyme';
import expect from 'expect'
import DocumentModel from '../../modules/model/DocumentModel'
import showModel from '../../modules/model/ShowModel'
let document = new DocumentModel({collection: "DSL", query: {companyId: "matrioska"}}, {populate: [{path: "accountId", model: "Account"}]}, [{label: "Nome", name: "name"}, {label: "Autore", name: "accountId._id"}, {label: "Data Ultima Modifica", name: "lastModifiedDate"}]);
let query = document.buildQuery();
let rows =[{label: "Nome", name: "name"}, {label: "Autore", name: "accountId._id"}, {label: "Data Ultima Modifica", name: "lastModifiedDate"}];
let populate = [{path: "accountId", model: "Account"}];

describe("DocumentModel", function()
{
  describe("GetCollection", function()
  {
    it("it should show the Collection of the query", function()
    {
      expect(document.getCollection()).toBe("DSL");
    })
  })

  describe("GetPopulate", function()
  {
    it("it should show the populate object of the DocumentModel", function()
    {
      expect(document.getPopulate()).toEqual(populate);
    })
  })

  describe("buildQuery()", function()
  {
    it("it should build the query of of the DocumenteMOdel",
      function()
      {
        expect(document.buildQuery()).toEqual("db.collection('DSL').find({\"companyId\":\"matrioska\"})");
      })
  })

/*  describe("JSONBuild()", function()
  {
    it("it should build the JSON of the mongo query",
      function()
      {
        expect(document.JSONbuild(query)).toEqual(
        {
          "properties":
          {
            "DSLType": "document",
            "rows": rows
          },
          "data":
          {
            "result": result
          }
      });
    })
  })*/

  describe("DSLType()", function()
  {
    it("it should show the DSLType of the Document",
      function()
      {
        expect(document.DSLType()).toBe("document");
      })
  })
  describe("GetRows", function()
  {
    it("it should return the value rows of the DSLI",
      function()
      {
        expect(document.getRows()).toEqual(rows);
      })
  })
})
