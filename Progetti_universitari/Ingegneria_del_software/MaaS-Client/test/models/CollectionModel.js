import React from 'react';
import
{
  shallow
}
from 'enzyme';
import expect from 'expect'
import CollectionModel from '../../modules/model/CollectionModel'

let collection = new CollectionModel({param: {name: "Account"}}, {param: {populate: [{path: "companyId", model: "Company"}]}, columns: [{label: "Email", name: "_id", sortable: true, selectable: true, transformation: {}}, {label: "Compagnia", name: "companyId._id", sortable: true, transformation: {}}, {label: "Boss", name: "companyId.ownerId", sortable: true, selectable: false, transformation: {}}]}, {populate: [{path: "companyId", model: "Company"}], rows: [{label: "Email", name: "_id"}, {label: "CompanyID", name: "companyId.ownerId"}]});

describe("CollectionModel", function()
{
  describe("getName()", function()
  {
    it("it should show the Name of the CollectionModel", function()
    {
      expect(collection.getName()).toBe("Account");
    })
  })
  describe("getName()", function()
  {
    it("it should show the Name of the CollectionModel", function()
    {
      expect(collection.getName()).toBe("Account");
    })
  })
  describe("getIndexColumns()",function(){
    it("it should show the Columns of the CollectionModel",function(){
      expect(collection.getIndexColumns()).toEqual([ { label: 'Email',
    name: '_id',
    sortable: true,
    selectable: true,
    transformation: {} },
  { label: 'Compagnia',
    name: 'companyId._id',
    sortable: true,
    transformation: {} },
  { label: 'Boss',
    name: 'companyId.ownerId',
    sortable: true,
    selectable: false,
    transformation: {} } ]
);
    })
  })
  describe("getShowRows()", function()
  {
    it("it should show the Rows of the CollectionModel", function()
    {
      expect(collection.getShowRows()).toEqual([ { label: 'Email', name: '_id' },
  { label: 'CompanyID', name: 'companyId.ownerId' } ])
    })
  })
  describe("getPopulate()", function()
  {
    it("it should show the indexPopulate of the CollectionModel", function()
    {
      expect(collection.getPopulate()).toEqual([ { path: 'companyId', model: 'Company' } ]);
    })
  })
  describe("getPopulateShow()", function()
  {
    it("it should show the indexPopulate of the CollectionModel", function()
    {
      expect(collection.getPopulateShow()).toEqual([ { path: 'companyId', model: 'Company' } ]);
    })
  })
  describe("DSLType()", function()
  {
    it("it should show the Type of the DSLI", function()
    {
      expect(collection.DSLType()).toBe("collection");
    })
  })
  describe("buildQuery()", function()
  {
    it("it should show the principal query of the DSLI", function()
    {
      expect(collection.buildQuery()).toBe('db.collection(\'Account\').find().sort({\'_id\': 1})');
    })
  })
  describe("buildQuery()", function()
  {
    it("it should show the principal query of the DSLI", function()
    {
      expect(collection.buildQuery()).toBe('db.collection(\'Account\').find().sort({\'_id\': 1})');
    })
  })
  /*
  describe("JSONbuild(result)", function()
  {
    it("it should show the json of the DSLI", function()
    {
      expect(collection.JSONbuild(result)).toBe('db.collection(\'Account\').find().sort({\'_id\': 1})');
    })
  })
  */
  //MAnca il render


})
